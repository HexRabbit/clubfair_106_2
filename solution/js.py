#!/usr/bin/env python3
#-*- coding: utf8 -*-
from urllib.parse   import quote
from urllib.request import urlopen


s1 = ''.join(chr(int(h1[i:i+2],16)) for i in range(0,len(h1),2))
s2 = ''.join(chr(int(h2[i:i+2],16)) for i in range(0,len(h2),2))

with open('./message1.bin', 'rb') as f:
    r1 = f.read()
with open('./message2.bin', 'rb') as f:
    r2 = f.read()
print(urlopen('https://js-saikou.herokuapp.com/?j='+quote(r1)+'&s='+quote(r2)).read())
