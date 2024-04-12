#include <bits/stdc++.h>
using namespace std;

long long cnt[4000005], sum[4000005];

const long long MOD = 1200000090 ;
long long fact[4000005];

long long pw(long long x, long long n, long long k) {
    if (n == 0) {
        return 1;
    }
    long long m = pw(x, n / 2, k) % k;
    if (n % 2 == 0) {
        return m * m % k;
    }
    return m * m % k * x % k;
}

int main() {
    freopen("input.txt", "r", stdin);  
    // x[k] = tong uoc tu 1 den 1e6
    for (int i = 1; i <= 4000005; i++) {
        for (int j = 1; i * j <= 4000005; j++) {
            sum[i*j] +=  i;
        }
    }
    
    // giai thua 
    fact[0] = 1;
    for (int i = 1; i <= 4000005; i++) {
        fact[i] = fact[i - 1] * i % MOD;
       // inv[i] = pw(fact[i], MOD - 2, MOD);
    }
    int t;
    cin >> t;
    for (int i = 1 ; i <= t; i++) {
        long long n;
        cin >> n;
        long long k = pw(fact[n],3,MOD); 
        cout <<sum[k];
        cout << '\n';
    }

      //  for (int i = 1; i<= 50; i++) cout<<i<<' '<<sum[i]<<endl;
   
    return 0;
}
 