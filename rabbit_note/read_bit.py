#!/usr/bin/env python3
from bitstring import BitArray

with open('a.out', 'rb') as f:
    binary = BitArray(f.read())

print(binary.bin)
