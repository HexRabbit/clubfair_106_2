#!/usr/bin/env python2
from bitstring import BitArray

arr = [
    0x0,
    0x0,
    0x0,
    0x0,
    0x1fd383fa7f0,
    0x1040d919410,
    0x175f8bb25d0,
    0x174fcaee5d0,
    0x175a0edf5d0,
    0x1042a8ad410,
    0x1fd555557f0,
    0x1cb4ba000,
    0xc5e1f7550,
    0x29a8e7dba0,
    0xde306cb650,
    0x1c874624910,
    0x18522bc6510,
    0x191e907fa20,
    0x13c064fe050,
    0x28f5ac3ef0,
    0x1ed02f245a0,
    0xd1a3136810,
    0x1ad9ffcf310,
    0x13252965b80,
    0x7d73ef5ef0,
    0x1e847043bf0,
    0x54363529b0,
    0xcb26386f00,
    0x1e650aefc20,
    0x15130c55460,
    0x137112c0230,
    0x179adb96860,
    0x10de6c4df50,
    0x1ca2b1100,
    0x1fcd81e5510,
    0x105a6cb11b0,
    0x174f25dbfa0,
    0x1745cc89c80,
    0x174e8c39ed0,
    0x1048cea7690,
    0x1fcabec5310,
    0x0,
    0x0,
    0x0,
    0x0
    ]

for i in arr:
    print BitArray(hex(i)).bin.rjust(45,'0').replace('1',' ')
