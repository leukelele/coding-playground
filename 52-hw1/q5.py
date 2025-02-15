import random

def transmit_received_sim(num_bits):

    # counters
    received_0 = 0
    received_1 = 0
    transmitted_1_and_received_1 = 0
    errors = 0

    for i in range(num_bits):

        # determine transmitted bit
        t = 0 if random.random() < 0.45 else 1

        # determine received bit
        if t == 0:
            r = 0 if random.random() < 0.85 else 1
        else:
            r = 1 if random.random() < 0.95 else 0

        # update counts
        if r == 0:
            received_0 += 1
        else:
            received_1 += 1
            if t == 1:
                transmitted_1_and_received_1 += 1
        if t != r:
            errors += 1
    
    # find avg
    part_a = received_0 / num_bits
    part_b = transmitted_1_and_received_1 / received_1
    part_c = errors / num_bits

    # output
    print(f"(a) probability that a 0 is received: {part_a:.6f}")
    print(f"(b) probability that a 1 was transmitted given a 1 was received: {part_b:.6f}")
    print(f"(c) probability of an error: {part_c:.6f}")


num_bits = 100000
transmit_received_sim(num_bits)
