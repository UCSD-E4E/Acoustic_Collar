#!/usr/bin/env python3
"""Convert a torchaudio float32 .bin to a C header with int16 PCM data.

Usage:
    python wav_to_header.py <input.bin> [output.h]

The input .bin is expected to contain float32 samples in [-1, 1]
(the output of torchaudio.load). The script converts them to int16 PCM
and writes a const int16_t array in a C header for STM32 testing.
"""

import sys
import struct
from pathlib import Path

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input.bin> [output.h]")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = (
        Path(sys.argv[2]) if len(sys.argv) > 2
        else Path(__file__).resolve().parent.parent / "CM7" / "Core" / "Inc" / "test_pcm.h"
    )

    data = input_path.read_bytes()
    num_floats = len(data) // 4
    floats = struct.unpack(f"<{num_floats}f", data[:num_floats * 4])

    # Convert float32 [-1, 1] to int16 [-32768, 32767]
    pcm = []
    for f in floats:
        val = int(f * 32767.0)
        val = max(-32768, min(32767, val))
        pcm.append(val)

    print(f"Input: {num_floats} float32 samples ({len(data)} bytes)")
    print(f"Duration: {num_floats / 16000:.3f}s at 16kHz")

    with open(output_path, "w") as out:
        out.write("#ifndef TEST_PCM_H\n")
        out.write("#define TEST_PCM_H\n\n")
        out.write(f"/* Auto-generated from {input_path.name} */\n")
        out.write(f"/* {len(pcm)} int16 PCM samples ({len(pcm) / 16000:.3f}s at 16kHz) */\n\n")
        out.write(f"#define TEST_PCM_SIZE {len(pcm)}\n\n")
        out.write(f"static const int16_t test_pcm[{len(pcm)}] = {{\n")

        for i in range(0, len(pcm), 16):
            chunk = pcm[i:i + 16]
            line = ", ".join(str(v) for v in chunk)
            out.write(f"    {line},\n")

        out.write("};\n\n")
        out.write("#endif /* TEST_PCM_H */\n")

    print(f"Written to {output_path} ({output_path.stat().st_size} bytes)")

if __name__ == "__main__":
    main()
