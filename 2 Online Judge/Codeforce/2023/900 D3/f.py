import math
import random
import sys

def countDiv(x):
    res = 0
    for i in range(1, int(math.sqrt(x)) + 1):
        if x % i == 0:
            res += 2

    z = int(math.sqrt(x))
    if z * z == x:
        res -= 1
    return res

def solve():
    n, t = map(int, input().split())
    d = {}
    d1 = {}

    tmp = n

    numDiv = 1
    nowDiv = 1

    if n != 1:
        for i in range(2, int(math.sqrt(n)) + 1):
            while tmp % i == 0:
                if i not in d:
                    d[i] = 0
                d[i] += 1
                tmp //= i

        if tmp > 1:
            d[tmp] = 1

        for i in d:
            d1[i] = d[i]
            numDiv *= (d[i] + 1)

    nowDiv = numDiv
    tmp = n

    for _ in range(t):
        type_values = input().split(' ')
        typez = int(type_values[0])
        if typez == 2:
            tmp = n
            nowDiv = numDiv
            d1 = dict(d)
        else:
            x = int(type_values[1])
            if x != 1:
                tmp *= x
                tt = x
                for i in range(2, int(math.sqrt(x)) + 1):
                    if tt % i == 0:
                        if (tt in d1): 
                            nowDiv //= (d1[i] + 1)
                        else: 
                            d1[i] = 0

                        while tt % i == 0:
                            d1[i] += 1
                            tt //= i
                        nowDiv *= (d1[i] + 1)
                if tt > 1:
                    if (tt in d1): 
                        nowDiv //= (d1[tt] + 1)
                    else: 
                        d1[tt] = 0
                    d1[tt] += 1
                    nowDiv *= (d1[tt] + 1)

            print(tmp, nowDiv)
            if tmp % nowDiv == 0:
                print("YES")
            else:
                print("NO")



sys.stdin = open("input.txt","r")
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
        print()