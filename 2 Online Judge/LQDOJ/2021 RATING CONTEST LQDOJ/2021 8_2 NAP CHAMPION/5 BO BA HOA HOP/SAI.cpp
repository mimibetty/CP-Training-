#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int a[100005];
long long fact[100005];
long long inv[100005];

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

long long combi(int n, int k) {
    if (n >= k) {
        return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    }
    return 0;
}


int b[1000005];
int trace[100005];
bool snt[100005];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }

 
 //	cout << combi(5, 2) << endl;
    //sieve
 	//vector<int> primes;
    sieve(100000);
    for (int i = 1; i <= 100000; i++) {
    	if (trace[i] == i) {
    		//primes.push_back(i);
    		snt[i] = 1;
    	}
    }


    int t;
    cin >> t;

 	for (int o = 1; o <= t; o++) {
 		long long res = 0;
 		int n;
 		cin >> n;
 		set<int>sntoo,normal;
 		for (int i = 1; i <= n; i++) {
 			cin >> b[i];
 			if (snt[b[i]] == 1) {
 				sntoo.insert(b[i]);
 			}
 			else normal.insert(b[i]); 
 		}	
 		int l = sntoo.size(), r = normal.size();
 		if (l >= 3) {
 			res += (combi(l,3));
 		}
 		if (r >= 3) {
 			res += (combi(r,3));
 		}
 		cout << res << endl;
 		sntoo.clear();
 		normal.clear();
 	}   

    return 0;
}