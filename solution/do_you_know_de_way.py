#!/usr/bin/python
import string
import re
from base64 import b64decode as d64
import itertools

test = ['vd','t3','fY','uaW','XJl','aHl','X3l','V9','W5','yd']

r = itertools.permutations(test)

for case in r:
    try:
        text = d64('Q0NOU3'+''.join(case)+'5nfQ==')
        if not all(c in string.printable for c in text):
            raise err

        match = re.search('^CCNS{[a-z_]*}$',text)

        if(match):
            print match.string
    except:
        pass
