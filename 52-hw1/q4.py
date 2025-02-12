import numpy as np

def multiplicative_congruential_generator(seed, k, m, n):
    values = []
    s = seed
    for _ in range(n):
        s = (k * s) % m
        values.append(s / m)
    return values

def generate_exponential_random_numbers(lambda_, random_numbers):
    return [- (1 / lambda_) * np.log(r) for r in random_numbers]

# Parameters
k = 16807
m = 2147483647
s0 = 1234
n = 10000
lambda_ = 2

# Generate uniformly distributed random numbers
uniform_random_numbers = multiplicative_congruential_generator(s0, k, m, n)

# Generate exponentially distributed random numbers
exponential_random_numbers = generate_exponential_random_numbers(lambda_, uniform_random_numbers)

# Compute mean and variance
mean = np.mean(exponential_random_numbers)
variance = np.var(exponential_random_numbers)

# Theoretical mean and variance
theoretical_mean = 1 / lambda_
theoretical_variance = 1 / (lambda_ ** 2)

# Print results
print(f"Simulated Mean: {mean:.6f}")
print(f"Theoretical Mean: {theoretical_mean:.6f}")
print(f"Simulated Variance: {variance:.6f}")
print(f"Theoretical Variance: {theoretical_variance:.6f}")
