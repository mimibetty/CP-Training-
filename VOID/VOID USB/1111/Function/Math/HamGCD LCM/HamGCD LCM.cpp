#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b > 0) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long lcm(long long a, long long b) {
    long long res = a * b / gcd(a, b);
    return res;
}
