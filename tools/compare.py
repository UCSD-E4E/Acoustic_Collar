import numpy as np
import matplotlib.pyplot as plt


stm32 = np.fromfile('/Users/mohak/Documents/GitHub/Projects/Acoustic_Collar/Calculated_mel_spec.bin', dtype=np.float32)
print(stm32.shape)
stm32=stm32.reshape(128, 188)
truth_raw = np.fromfile('/Users/mohak/Documents/GitHub/Projects/Acoustic_Collar/label_1_mel.bin', dtype=np.float32)
print(truth_raw.shape)
# Ground truth has 3 repeated channels (3, 128, 188) — take just the first
truth = truth_raw[:128 * 188].reshape(128, 188)

# Trim to matching frames if ground truth has different frame count
min_frames = min(stm32.shape[1], truth.shape[1])
stm32 = stm32[:, :min_frames]
truth = truth[:, :min_frames]

print(f"MSE: {np.mean((stm32 - truth)**2):.8f}")
print(f"Max abs diff: {np.max(np.abs(stm32 - truth)):.8f}")

plt.figure(figsize=(10, 4))
# Use the first channel for display
plt.imshow(stm32, origin='lower', aspect='auto', cmap='viridis')
plt.title("Mel Spectrogram")
plt.xlabel("Time (frames)")
plt.ylabel("Mel Frequency Bin")
plt.colorbar(label="Amplitude (dB)")
plt.tight_layout()
plt.show()


plt.figure(figsize=(10, 4))
# Use the first channel for display
plt.imshow(truth, origin='lower', aspect='auto', cmap='viridis')
plt.title("Mel Spectrogram")
plt.xlabel("Time (frames)")
plt.ylabel("Mel Frequency Bin")
plt.colorbar(label="Amplitude (dB)")
plt.tight_layout()
plt.show()
