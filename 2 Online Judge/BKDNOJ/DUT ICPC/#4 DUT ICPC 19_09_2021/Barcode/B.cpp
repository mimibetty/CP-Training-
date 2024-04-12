#include <bits/stdc++.h>
using namespace std;

long long fact[1000005];
long long inv[1000005];
long long vp[1000005];

// tính combi(n, k) với mọi p
long long pw(long long a, long long n, long long m) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, m);
    if (n % 2 == 0) return q * q % m;
    else return q * q % m * a % m;
}

long long combi(long long n, long long k, long long m) {
    if (n < k) return 0;
    if (vp[n] > vp[n - k] + vp[k]) return 0;
    return fact[n] * inv[k] % m * inv[n - k] % m;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        long long n,p;
        cin>>n>>p;
        long long res = 0;
        fact[0] = 1;
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            int val = i; vp[i] = vp[i - 1];
            while (val % p == 0) {
                vp[i]++;
                val /= p;
            }

            fact[i] = fact[i - 1] * val % p;
            inv[i] = pw(fact[i], p - 2, p);
        }
        long long x;
        if (n%2==1) x=0;
        else x=combi(n,n/2,p);
        long long f1=2,f2=3,f3;
        if (n == 1) f3 = 2%p; 
        else if (n == 2) f3 = 3%p;
        else {
            for (int i=3;i<=n;i++)
            {
                f3=(f1+f2)%p;
                f1=f2%p;
                f2=f3%p;
            }
        }
        cout << x << endl;
        if (n%2==1) res = f3%p;
        else  res = x+f3-1-(n/2);
        res = (res%p + p) %p; 
        cout << res << endl;       
    }
}