import numpy as np

def multiplicative_congruential_generator(seed, k, m, n):
    values = []
    values.append(seed)
    s = values[0]
    for i in range(1, n+1):
        s = (k * s) % m
        values.append(s / m)
    return values[1:]

# parameters
k = 16807
m = 2147483647
s0 = 1234
n = 10000

# generate random numbers
rand_num = multiplicative_congruential_generator(s0, k, m, n)

# compute mean and variance
mean = np.mean(rand_num)
variance = np.var(rand_num)

# count occurrences in each interval
intervals = np.zeros(10, dtype=int)
for rn in rand_num:
    index = int(rn * 10)
    if index == 10:             # Edge case for 1.0
        index = 9
    intervals[index] += 1

# output
print(f"Mean: {mean:.6f}")
print(f"Variance: {variance:.6f}")
print("Intervals:")
for i, count in enumerate(intervals, start=1):
    print(f"[{(i-1)/10:.1f}, {i/10:.1f}]: {count}")
