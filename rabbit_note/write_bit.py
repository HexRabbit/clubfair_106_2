#!/usr/bin/env python3
from bitstring import BitArray

with open('output', 'r') as f:
    s = f.read()

binary = BitArray('0b'+s)

with open('recovered', 'w+b') as f:
    f.write(binary.bytes)


