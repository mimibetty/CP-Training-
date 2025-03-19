import random
import os

MOD = 998244353

def s(k):
    if k > 0: return 1
    if k < 0: return -1
    return 0

def calculate_total_power(heroes):
    total = 0
    n = len(heroes)
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                a, x = heroes[i]
                b, y = heroes[j]
                c, z = heroes[k]
                # Check valid condition
                if not (a >= b + c or b >= a + c or c >= a + b):
                    D = 1 + abs(s(x - y)) + abs(s(x*y - x*z + z*z - y*z))
                    power = (a + b + c) * D
                    total = (total + power) % MOD
    return total

def generate_test_case(filename, maxn, maxpower, maxskill):
    n = random.randint(3, maxn)
    heroes = [(random.randint(1, maxpower), random.randint(1, maxskill)) for _ in range(n)]
    # Write input to file
    with open(filename + '.inp', 'w') as fin:
        fin.write(f"{n}\n")
        for p, q in heroes:
            fin.write(f"{p} {q}\n")
    # Calculate output
    result = calculate_total_power(heroes)
    # Write output to file
    with open(filename + '.out', 'w') as fout:
        fout.write(f"{result}\n")

def main():
    t = int(input("Number of test cases (t): "))
    maxn_limit = int(input("Max limit for number of heroes (maxn): "))
    maxpower_limit = int(input("Max limit for combat strength (maxpower): "))
    maxskill_limit = int(input("Max limit for skill code (maxskill): "))

    # Create directory for test cases
    os.makedirs("test_cases", exist_ok=True)

    for test_num in range(1, t+1):
        maxn = random.randint(1000, 2000)
        maxpower = random.randint(1, maxpower_limit)
        maxskill = random.randint(1, maxskill_limit)

        filename = f"test_cases/test{test_num}"
        print(f"Generating {filename}.inp and {filename}.out (n={maxn}, maxpower={maxpower}, maxskill={maxskill})")
        generate_test_case(filename, maxn, maxpower, maxskill)

    print("All test cases generated successfully in 'test_cases' directory!")

if __name__ == "__main__":
    main()