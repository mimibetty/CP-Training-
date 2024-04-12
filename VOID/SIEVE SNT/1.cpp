#include <bits/stdc++.h>
using namespace std;

const int lim7 = 1e7 + 5;
int trace[10000005]; // trace[i] là ước NT lớn nhất của i
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


// Tong UOC n log 
for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            x[i*j].first +=  i;
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
vector<bool> isPrime(R - L + 1, true);  // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true

for (long long i = 2; i * i <= R; ++i) {
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
        isPrime[j - L] = false;
    }
}

if (1 >= L) {  // Xét riêng trường hợp số 1
    isPrime[1 - L] = false;
}

for (long long x = L; x <= R; ++x) {
    if (isPrime[x - L]) {
        // i là số nguyên tố
    }
}

