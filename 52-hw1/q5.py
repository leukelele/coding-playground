import random

def simulate_channel(num_bits=100000):
    received_0 = 0
    received_1 = 0
    transmitted_1_and_received_1 = 0
    errors = 0

    for _ in range(num_bits):
        # Determine transmitted bit
        tx = 0 if random.random() < 0.45 else 1

        # Determine received bit
        if tx == 0:
            rx = 0 if random.random() < 0.85 else 1
        else:
            rx = 1 if random.random() < 0.95 else 0

        # Update counts
        if rx == 0:
            received_0 += 1
        else:
            received_1 += 1
            if tx == 1:
                transmitted_1_and_received_1 += 1

        if tx != rx:
            errors += 1

    prob_a = received_0 / num_bits
    prob_b = transmitted_1_and_received_1 / received_1 if received_1 > 0 else 0.0
    prob_c = errors / num_bits

    print(f"(a) Probability that a 0 is received: {prob_a:.4f}")
    print(f"(b) Probability that a 1 was transmitted given a 1 was received: {prob_b:.4f}")
    print(f"(c) Probability of an error: {prob_c:.4f}")

simulate_channel()
