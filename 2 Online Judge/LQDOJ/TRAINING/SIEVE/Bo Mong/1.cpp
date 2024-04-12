#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int lim7 = 1e7 + 5;
int trace[10000005]; // trace[i] là ước NT lớn nhất của i
int p[10000005];
long long d[10000005];
long long L,R;


long long pw(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(x, n / 2);
    if (n % 2 == 0) {
        return q * q % MOD;
    }
    else {
        return q * q % MOD * x % MOD;
    }
}

// faster
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (trace[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (trace[j] == 0) {
                    trace[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (trace[i] == 0) {
            trace[i] = i;
        }
    }
}

long long &getD(long long i) {
    return d[L-i+1];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long res = 1;
    set<long long>s;
    vector<int>primes;
       
    cin >> L >> R;
    sieve(1e7);
    
    int stt = 1;        
    for (long long i = L; i <= R; i++) {
        d[stt] = i;
        stt++;
    }
    stt--;

    for (int i = 2; i <= 1e7; i++) {
        if (trace[i] == i) primes.push_back(i);
    }

    for (auto i : primes) {
            for (auto j = ((L + i - 1) / i) * i; j <= R; j += i) {
                int maxVal = p[i];
                p[i] = 0;
                while ( getD(j) % i == 0) {
                    getD(j) /= i;
                    p[i]++;
                }
                p[i] = max(maxVal,p[i]);
            }
    }
    for (int i = 1; i <= stt; i++) {
        if (d[i] != 1) s.insert(d[i]);
    }
 
    for (auto i : primes) {
        res *= (pw(i, p[i]));
        res %= MOD;
    }
    
    for (auto i : s) {
        res *= (i % MOD);
        res %= MOD;
    }

    cout << res;
    return 0;
}