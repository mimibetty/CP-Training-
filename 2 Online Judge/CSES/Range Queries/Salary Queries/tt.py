
a = [1, 2, 5, 10, 20, 50, 100, 200, 500]

def main():
    n = int(input())
    d = [0] * 9
    total = sum(a)

    for i in range(8, -1, -1):
        d[i] = n // total
        n -= d[i] * total
        total -= a[i]

    res = [0] * 9
    res[8] = d[8]

    for i in range(7, -1, -1):
        res[i] = d[i] + res[i + 1]

    # Print the results
    for i in range(9):
        print(a[i], res[i])

if __name__ == "__main__":
    main()