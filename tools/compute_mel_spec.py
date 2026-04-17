#!/usr/bin/env python3
"""Compute mel spectrogram matching STM32 parameters.

Uses n_fft=512, hop_length=256 to match CMSIS-DSP power-of-2 FFT constraint.
All other parameters match the STM32 mel_spectrogram.c implementation.

Usage:
    python compute_mel_spec.py <wav_path> [--save-bin output.bin]
"""

import argparse
import torch
import torchaudio
import numpy as np


def compute_mel_spec(wav_path, sample_rate=16000, duration=3.0, channels=3):
    mel_transform = torchaudio.transforms.MelSpectrogram(
        sample_rate=sample_rate,
        n_fft=400,           
        hop_length=256,      
        n_mels=128,
        f_min=0.0,
        f_max=8000.0,
        center=True,         
        norm=None,          
        mel_scale="htk",    
        power=2.0,           
    )
    db_transform = torchaudio.transforms.AmplitudeToDB(
        stype="power",
        top_db=80.0,         
    )

    waveform, sr = torchaudio.load(wav_path)

    # resample if needed
    if sr != sample_rate:
        resampler = torchaudio.transforms.Resample(orig_freq=sr, new_freq=sample_rate)
        waveform = resampler(waveform)

    # convert to mono
    if waveform.shape[0] > 1:
        waveform = waveform.mean(dim=0, keepdim=True)

    target_length = int(sample_rate * duration)

    # pad or truncate to target length
    if waveform.shape[1] < target_length:
        pad_amount = target_length - waveform.shape[1]
        waveform = torch.nn.functional.pad(waveform, (0, pad_amount))
    else:
        waveform = waveform[:, :target_length]

    # compute mel spectrogram + dB
    mel = mel_transform(waveform)
    mel_db = db_transform(mel)

    # z-score normalization 
    mel_db = (mel_db - mel_db.mean()) / (mel_db.std() + 1e-6)

    # repeat to N channels
    mel_db = mel_db.repeat(channels, 1, 1)  # [channels, 128, time]

    return mel_db, waveform


def main():
    parser = argparse.ArgumentParser(description="Compute mel spectrogram matching STM32")
    parser.add_argument("wav_path", help="Path to .wav file")
    parser.add_argument("--save-bin", help="Save mel spec as float32 .bin")
    parser.add_argument("--save-wav-bin", help="Save PCM waveform as float32 .bin")
    parser.add_argument("--duration", type=float, default=3.0, help="Duration in seconds")
    parser.add_argument("--channels", type=int, default=3, help="Number of repeated channels")
    args = parser.parse_args()

    mel_db, waveform = compute_mel_spec(args.wav_path, duration=args.duration, channels=args.channels)

    print(f"Mel spectrogram shape: {mel_db.shape}")
    print(f"  (channels={mel_db.shape[0]}, n_mels={mel_db.shape[1]}, frames={mel_db.shape[2]})")
    print(f"Waveform shape: {waveform.shape}")
    print(f"Value range: [{mel_db.min():.4f}, {mel_db.max():.4f}]")
    print(f"Mean: {mel_db.mean():.6f}, Std: {mel_db.std():.6f}")

    if args.save_bin:
        mel_db.numpy().astype(np.float32).tofile(args.save_bin)
        print(f"Saved mel spec to {args.save_bin}")

    if args.save_wav_bin:
        waveform.numpy().astype(np.float32).tofile(args.save_wav_bin)
        print(f"Saved waveform to {args.save_wav_bin}")


if __name__ == "__main__":
    main()
