#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int a[100005];
long long fact[100005];
long long inv[100005];


long long pw(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(a, n / 2)%MOD;
    if (n % 2 == 0) {
        return q*q%MOD ;
    }
    else {
        return q*q%MOD  * a%MOD ;
    }
}

long long combi(int n, int k) {
    if (n >= k) {
        return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    }
    return 0;
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
 	int n ,cnt5 = 0;
 	long long res  = 0;
 	long long k;
 	cin >> n >> k;
 	long long c = k;
 	while (c % 5 == 0) {
 		c/= 5;
 		cnt5++;
 	}
 	
 	for (int i  = 0; i <= n; i++ ) {
 		for (int j = 0 ; j <= n; j++) {
 			for (int l = 0; l <= n; l++) {
 				for (int r = 0; r <= n; r++) {
 					if (pw(2,r) * pw(3,l) * pw(4,j) * pw(6,i) * pw(5,cnt5) > res) break;
 					else if (pw(2,r) * pw(3,l) * pw(4,j) * pw(6,i) * pw(5,cnt5) == res) {
 						long long cnt1 = n - i - j - l - r - cnt5;
 						long long cnt = combi(n,r) * combi(n-r,l) * combi(n-r-l,j) * combi(n-r-l-j,i) * combi(n-r-l-i-j,cnt1);  
 						res += cnt; 
 					}
 				}
 			}
 		}
 	}
 	cout << res;

    return 0;
}