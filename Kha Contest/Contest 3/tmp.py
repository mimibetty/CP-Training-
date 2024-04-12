
import sys


def int_to_bin(n):
    return bin(n)[2:]

def solve1():
    # sys.stdin = open("input.txt","r")
    x = 1
    a = [1]
    limm = pow(10,30)
    # print(limm)
    while x < limm:
        x *= 3
        a.append(x)


    while True:
        n = int(input())
        if n == 0: 
            return
        x = int_to_bin(n - 1)
        res = []
        # print(x)
        
        lenn = len(x)
        print("{",end =" ")
        for i in range(0,len(x)):
            if (x[lenn - i -1] == '1'):
                # print(a[i],end = ' ');
                res.append(a[i])

        for i in range(0, len(res)):
            if (i != 0):
                print(" ", end="")
            print(res[i], end="")
            if (i != len(res) - 1):
                print(",", end="")
        if (n != 1): print(" ",end="")
        print("}")


solve1()