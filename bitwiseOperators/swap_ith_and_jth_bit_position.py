def swap_ij_bits(x, i, j):
    bitmask = (1 << i) | (1 << j)
    x ^= bitmask
    return x


print(swap_ij_bits(5, 1, 2))
