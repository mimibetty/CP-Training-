#include <bits/stdc++.h>
using namespace std;

const int lim7 = 1e7 + 5;
int trace[10000005]; // trace[i] là ước NT nhỏ nhất của i
int a[10000005];
int s[10000005];

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
// trace[i] == uoc nt max cua i 
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}

// Tong UOC n log 
for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            x[i*j] +=  i;
        }
    }



// pt thua so ngto trong O(log) 
int minPrime[n + 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) { //if i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}

vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}


// sang nto trong khoang [l,r] 
//DPT O(sqrt(r) * k)
for (auto i : primes) {
            ll firstnum = (L-1)/i * i + i;
            ll lastnum = R/i * i;
            for (auto j = firstnum; j <= lastnum; j += i) {
                while ( d[j - L + 1] % i == 0) {
                    d[j - L + 1] /= i;
                }
            }
    }