#!/usr/bin/python3.5

import sys


n = int(input().strip())
arr = [arr_temp for arr_temp in input().strip().split(' ')]

arr.reverse()
print(' '.join(arr))