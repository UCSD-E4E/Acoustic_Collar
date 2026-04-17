#!/usr/bin/env python3
"""Automated inference pipeline for STM32 acoustic collar.

Protocol (per trial):
  Python  → STM32 : "START\r\n"
  STM32   → Python: "RECORDING\r\n"
  Python  plays .wav through speaker while STM32 records via PDM mic
  STM32   → Python: "SCORES:<v0>,<v1>,...,<v5>\r\n"   (values = score*100, int)
  STM32   → Python: "PREDICTION:<ClassName>\r\n"
  Python  logs row to CSV

Usage:
    python inference_pipeline.py <audio_dir> <serial_port> [--baud 115200]

Example:
    python inference_pipeline.py ./recordings /dev/tty.usbmodem14103
"""

import argparse
import csv
import sys
import time
from pathlib import Path

import serial
import sounddevice as sd
import soundfile as sf


CLASS_NAMES = ["Cluck", "Coocoo", "Twitter", "Alarm", "Chick Begging", "no_buow"]

# Seconds to wait for each response before giving up
HANDSHAKE_TIMEOUT = 10   # "RECORDING" reply
RESULT_TIMEOUT    = 30   # "SCORES" + "PREDICTION" lines


def parse_args():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("audio_dir",    type=Path, help="Directory containing .wav files")
    p.add_argument("serial_port",  type=str,  help="Serial port (e.g. /dev/tty.usbmodem14103)")
    p.add_argument("--baud",       type=int,  default=115200)
    p.add_argument("--output", "-o", type=Path, default=Path("inference_results.csv"))
    p.add_argument("--repeats",    type=int,  default=1,
                   help="How many times to play each file (default: 1)")
    return p.parse_args()


def discover_audio_files(audio_dir: Path) -> list[Path]:
    files = sorted(audio_dir.glob("*.wav"))
    if not files:
        print(f"No .wav files found in {audio_dir}")
        sys.exit(1)
    return files


def read_line(ser: serial.Serial, timeout: float) -> str:
    """Read one CRLF-terminated line, stripping whitespace. Returns '' on timeout."""
    deadline = time.time() + timeout
    buf = b""
    while time.time() < deadline:
        if ser.in_waiting:
            ch = ser.read(1)
            buf += ch
            if ch == b"\n":
                line = buf.decode("utf-8", errors="replace").strip()
                print(f"  STM32> {line}")
                return line
        else:
            time.sleep(0.01)
    return ""


def wait_for_prefix(ser: serial.Serial, prefix: str, timeout: float) -> str:
    """Read lines until one starts with *prefix* or timeout. Returns the matching line."""
    deadline = time.time() + timeout
    while time.time() < deadline:
        line = read_line(ser, deadline - time.time())
        if line.startswith(prefix):
            return line
    return ""


def play_audio(wav_path: Path):
    """Play a wav file through the default audio output, blocking until done."""
    data, sr = sf.read(wav_path, dtype="float32")
    if data.ndim > 1:
        data = data[:, 0]
    duration = len(data) / sr
    print(f"  Playing {wav_path.name} ({duration:.2f}s @ {sr} Hz)")
    sd.play(data, samplerate=sr)
    sd.wait()


def run_trial(ser: serial.Serial, wav_path: Path) -> dict:
    """Execute one START→RECORDING→play→SCORES→PREDICTION cycle.

    Returns a dict with 'scores' (list of floats) and 'predicted' (str).
    """
    result = {"scores": [], "predicted": None}

    # Send START
    ser.write(b"START\r\n")
    ser.flush()

    # Wait for RECORDING acknowledgement
    line = wait_for_prefix(ser, "RECORDING", HANDSHAKE_TIMEOUT)
    if not line:
        print("  ERROR: no RECORDING response from STM32")
        return result

    # Play audio (STM32 is now capturing)
    play_audio(wav_path)

    # Collect SCORES line
    scores_line = wait_for_prefix(ser, "SCORES:", RESULT_TIMEOUT)
    if scores_line:
        raw = scores_line[len("SCORES:"):].strip()
        try:
            result["scores"] = [int(v) / 100.0 for v in raw.split(",")]
        except ValueError:
            print(f"  WARNING: could not parse scores: {raw!r}")

    # Collect PREDICTION line
    pred_line = wait_for_prefix(ser, "PREDICTION:", RESULT_TIMEOUT)
    if pred_line:
        result["predicted"] = pred_line[len("PREDICTION:"):].strip()

    return result


def main():
    args = parse_args()
    wav_files = discover_audio_files(args.audio_dir)
    print(f"Found {len(wav_files)} audio file(s) in {args.audio_dir}")

    ser = serial.Serial(args.serial_port, args.baud, timeout=1)
    print(f"Opened {args.serial_port} @ {args.baud} baud")
    time.sleep(2)  # let serial settle
    ser.reset_input_buffer()

    # Wait for READY from STM32
    print("Waiting for STM32 READY...")
    ready = wait_for_prefix(ser, "READY", timeout=30)
    if not ready:
        print("ERROR: STM32 did not send READY within 30s")
        ser.close()
        sys.exit(1)
    print("STM32 is ready.\n")

    fieldnames = ["file", "repeat"] + [f"score_{c}" for c in CLASS_NAMES] + ["predicted"]
    csv_file = open(args.output, "w", newline="")
    writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
    writer.writeheader()

    total = len(wav_files) * args.repeats
    n = 0
    try:
        for wav_path in wav_files:
            for rep in range(1, args.repeats + 1):
                n += 1
                print(f"[{n}/{total}] {wav_path.name} (repeat {rep})")

                result = run_trial(ser, wav_path)

                row = {"file": wav_path.name, "repeat": rep, "predicted": result["predicted"]}
                for i, cls in enumerate(CLASS_NAMES):
                    row[f"score_{cls}"] = result["scores"][i] if i < len(result["scores"]) else ""
                writer.writerow(row)
                csv_file.flush()

                print(f"  => Predicted: {result['predicted']}")
                print()

    except KeyboardInterrupt:
        print("\nInterrupted by user.")
    finally:
        csv_file.close()
        ser.close()
        print(f"Results saved to {args.output}")


if __name__ == "__main__":
    main()
