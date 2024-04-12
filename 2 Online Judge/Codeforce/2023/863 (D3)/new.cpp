#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long pow_mod(long long a, long long b) {
    if (b == 0) return 1;

    long long res = pow_mod(a,b/2);
    if (b % 2 == 0) return 1ll * res % MOD * res % MOD;
    else return 1ll * res % MOD * res % MOD * a% MOD;
}

int main() {
 
    long long n;
    cin >> n;

    unsigned long long sotang = (pow_mod(2, n) + 1) % MOD;
    unsigned long long res = (sotang * (sotang + 1) / 2) % MOD;

    cout << res << endl;
    return 0;
}
