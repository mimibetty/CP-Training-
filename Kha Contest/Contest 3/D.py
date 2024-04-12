
# link submit: 
# Note:

import math
import sys


def log_base_k(num, base):
    return math.log(num) / math.log(base)

def pw(a, b):
    if b == 0:
        return 1
    q = pw(a, b // 2)
    if b % 2 == 0:
        return q*q
    else:
        return q*q*a

def solve():
    # sys.stdin = open("input.txt","r")
    n = int(input())
    while n != 0:
        res = 1
        for i in range(2, 33):
            base = i
            x = int(log_base_k(n, base))
            # print(i,x, pw(x,i))
            for j in range(-100, 101):
                tmp = x + j
                if tmp <= 0:
                    continue
                z = pw(tmp, base)
                if z > n:
                    break
                if z == n:
                    res = max(res, i)
        print(res)
        n = int(input())

solve()