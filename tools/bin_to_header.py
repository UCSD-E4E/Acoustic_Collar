#!/usr/bin/env python3
"""Convert a .bin file (float32 mel spectrogram) to a C header for STM32 testing.

Usage:
    python bin_to_header.py <input.bin> [output.h]

The input .bin is expected to contain 30,848 float32 values (128 x 241).
The script replicates the data 3x to match the model input size of 92,544 floats
(3 x 128 x 241) and writes it as a const float array in a C header.
"""

import sys
import struct
from pathlib import Path

FRAME_SIZE = 30848  # 128 * 241
REPLICATE = 3
TOTAL_SIZE = FRAME_SIZE * REPLICATE  # 92544

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input.bin> [output.h]")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2]) if len(sys.argv) > 2 else Path(__file__).resolve().parent.parent / "CM7" / "Core" / "Inc" / "test_melspec.h"

    data = input_path.read_bytes()
    num_floats = len(data) // 4

    if num_floats != FRAME_SIZE:
        print(f"Warning: expected {FRAME_SIZE} floats ({FRAME_SIZE * 4} bytes), "
              f"got {num_floats} floats ({len(data)} bytes)")

    floats = struct.unpack(f"<{num_floats}f", data[:num_floats * 4])

    # Replicate 3x to fill the full model input
    full_input = floats * REPLICATE

    with open(output_path, "w") as f:
        f.write("#ifndef TEST_MELSPEC_H\n")
        f.write("#define TEST_MELSPEC_H\n\n")
        f.write(f"/* Auto-generated from {input_path.name} */\n")
        f.write(f"/* {num_floats} floats replicated {REPLICATE}x = {len(full_input)} total */\n\n")
        f.write(f"static const float test_melspec[{len(full_input)}] = {{\n")

        for i in range(0, len(full_input), 8):
            chunk = full_input[i:i + 8]
            line = ", ".join(f"{v:.8e}f" for v in chunk)
            f.write(f"    {line},\n")

        f.write("};\n\n")
        f.write("#endif /* TEST_MELSPEC_H */\n")

    print(f"Written {len(full_input)} floats to {output_path}")
    print(f"File size: {output_path.stat().st_size} bytes")

if __name__ == "__main__":
    main()
