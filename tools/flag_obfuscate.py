#!/usr/bin/env python
import sys
from pwn import *

s = sys.argv[1]
n = int(sys.argv[2],16) if len(sys.argv) >= 3 else 0xDEADBEEF
print s, hex(n)
s += '\x00'

s += '\x00' * (4 - len(s)%4)

for i in range(0, len(s), 4):
    print hex(u32(s[i:i+4]) ^ n)
