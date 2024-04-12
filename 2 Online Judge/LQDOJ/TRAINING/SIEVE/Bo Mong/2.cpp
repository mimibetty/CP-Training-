#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long MOD = 1e9 + 7;
const int lim7 = 1e7 + 5;
int trace[10000005]; // trace[i] là ước NT lớn nhất của i

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

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long res = 1;
    map<long long, long long>d,p;
    set<long long>s;
    vector<int>primes;
    
    long long L,R;
    cin >> L >> R;
        
    for (long long i = L; i <= R; i++) d[i] = i;
    sieve(1e7);

    for (int i = 2; i <= 1e7; i++) {
        if (trace[i] == i) primes.push_back(i);
    }

    for (int i = L; i <= R; i++) {
        
    } 
    cout << res;
    return 0;
}