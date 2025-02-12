import numpy as np

def multiplicative_congruential_generator(seed, k, m, n):
    values = []
    s = seed
    for i in range(n):
        s = (k * s) % m
        values.append(s / m)
    return values

# Parameters
k = 16807
m = 2147483647
s0 = 1234
n = 10000

# Generate random numbers
random_numbers = multiplicative_congruential_generator(s0, k, m, n)

# Compute mean and variance
mean = np.mean(random_numbers)
variance = np.var(random_numbers)

# Count occurrences in each interval
bins = np.zeros(10, dtype=int)
for rn in random_numbers:
    index = int(rn * 10)  # Convert to bin index
    if index == 10:
        index = 9         # Edge case for 1.0
    bins[index] += 1

# Print results
print(f"Mean: {mean:.6f}")
print(f"Variance: {variance:.6f}")
print("Bin counts:")
for i, count in enumerate(bins, start=1):
    print(f"[{(i-1)/10:.1f}, {i/10:.1f}]: {count}")
