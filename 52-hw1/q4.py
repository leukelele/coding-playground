import numpy as np

def multiplicative_congruential_generator(seed, k, m, n):
    values = []
    values.append(seed)
    s = values[0]
    for i in range(1, n + 1):
        s = (k * s) % m
        values.append(s / m)
    return values[1:]

# Parameters for MCG
k = 16807
m = 2147483647
s0 = 1234
n = 10000

# generate random numbers
rand_num = multiplicative_congruential_generator(s0, k, m, n)

## compute mean and variance
#mean = np.mean(rand_num)
#variance = np.var(rand_num)
#
## count occurrences in each interval
#intervals= np.zeros(10, dtype=int)
#for rn in rand_num:
#    index = int(rn * 10)
#    if index == 10:             # Edge case for 1.0
#        index = 9
#    intervals[index] += 1
#
## output
#print(f"Mean: {mean:.6f}")
#print(f"Variance: {variance:.6f}")
#print("intervals counts:")
#for i, count in enumerate(intervals, start=1):
#    print(f"[{(i-1)/10:.1f}, {i/10:.1f}]: {count}")

# convert to exponential distro
lambda_param = 2
expo_rand_num = [(-np.log(r) / lambda_param) for r in rand_num]

# compute means and variances
sample_mean = np.mean(expo_rand_num)
sample_variance = np.var(expo_rand_num)
theoretical_mean = 1 / lambda_param
theoretical_variance = 1 / (lambda_param ** 2)

# output for q4
print(f"Sample Mean: {sample_mean:.6f}, Theoretical Mean: {theoretical_mean:.6f}")
print(f"Sample Variance: {sample_variance:.6f}, Theoretical Variance: {theoretical_variance:.6f}")
