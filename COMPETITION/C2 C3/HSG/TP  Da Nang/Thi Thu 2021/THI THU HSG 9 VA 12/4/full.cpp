#include<bits/stdc++.h>
using namespace std;

int a[1000005];

const long long MOD = 1e9 + 7;

long long pw(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long m = pw(x, n / 2) % MOD;
    if (n % 2 == 0) {
        return m * m % MOD;
    }
    return m * m % MOD * x % MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n;
    cin >> n;

    cout << pw(3,n-1);

    return 0;
}