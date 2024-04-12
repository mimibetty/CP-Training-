#include<bits/stdc++.h>
using namespace std;
const long long mod= 1e9+7;
long long pw(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(a, n / 2);
    if (n % 2 == 0) {
        return q*q%mod ;
    }
    else {
        return q*q%mod  * a %mod ;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	long long n, res = 0;
 	cin >> n;
 	long long sum = 0,hieu=0;
 	for (int i = 1; i <= n; i++)  {
 		long long a;
 		cin >> a;
 		sum += a;
        sum %= mod;
  		hieu += (a*a);
        hieu %= mod;
 	}
 	res = sum * sum - hieu;
	res = (res % mod + mod) % mod;
	cout << res * pw(2, mod - 2) % mod;

    return 0;
}