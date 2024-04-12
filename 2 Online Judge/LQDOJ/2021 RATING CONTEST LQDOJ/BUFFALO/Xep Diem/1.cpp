#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int a[200005];
long long fact[200005];
long long inv[200005];

long long pw(long long x, long long n) {
    if (n == 0) return 1;
    long long m = pw(x, n / 2) % MOD;
    if (n % 2 == 0) return m * m % MOD;
    return m * m % MOD * x % MOD;
}

long long combi(int n, int k) {
    if (n >= k) {
        return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    }
    return 0;
}

int main() {
        freopen("input.txt", "r", stdin);
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 200005; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }
    vector<int>pt;
    int n;
    cin >> n ;
    map<int,int> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }

    for (auto i : d) {
        if (i.second >= 2) pt.push_back(i.first); 
    }
    long long res = 0;
    
    for (int i = 0; i < pt.size(); i++) {
        for (int j = i+1; j < pt.size(); j++) {
            res += (combi(d[pt[i]],2)%MOD * combi(d[pt[j]],2)%MOD );
            res %= MOD;
        }
    }
    for (int i = 0; i < pt.size(); i++) if(d[pt[i]] >= 4) {
        res += combi(d[pt[i]],4);
        res %= MOD;
    }
    cout << res;
    return 0;
}