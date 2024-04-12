#include <bits/stdc++.h>
using namespace std;

long long fact[1000005];
// long long inv[1000005];

// tính combi(n, k) với mọi p
long long pw(long long a, long long n, long long m) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, m);
    if (n % 2 == 0) return q * q % m;
    else return q * q % m * a % m;
}

// long long combi(long long n, long long k, long long m) {
//     if (n < k) return 0;
//     if (vp[n] > vp[n - k] + vp[k]) return 0;
//     return fact[n] * inv[k] % m * inv[n - k] % m;
// }

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        long long res = 0;
        long long n,p;
        long long f1=2,f2=3,f3;
        long long vp_tu = 0, vp_mau = 0;

        cin>>n>>p;

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
            
        if (n%2==1) {
            res = f3 %p;
            cout << res << endl;
            continue;
        }
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 1; i <= n; i++) {
            if (i <= (n/2)) {
                int val = i;
                while (val % p == 0) {
                    vp_mau++;
                    val /= p;
                }

                fact[i] = fact[i - 1] * val % p;
                fact[i] %=p;
            }
            else {
                int val = i; 
                while (val % p == 0) {
                    vp_tu++;
                    val /= p;
                }
                if (i == (n/2) + 1) {
                    fact[i] = i%p;
                    continue;  
                } 
                fact[i] = fact[i - 1] * val % p;   
                fact[i] %=p;
            }
           
        }
       
        long long x = 0;
        if (vp_tu > vp_mau) x = 0;
        else x = fact[n]%p * pw(fact[n/2], p-2, p)%p;
        x%=p;
        // cout << fact[n]%p << endl;
        // cout << fact[n/2]%p << endl;
        // cout <<pw(fact[n/2], p-2, p)%p << endl;
        // cout << fact[n]%p * pw(fact[n/2], p-2, p)%p << endl;
        // cout << vp_tu  << ' ' << vp_mau << endl;
        // cout << x << endl;;
        res = x+f3-1-(n/2);
        res = (res%p + p) %p; 
        cout << res << endl;       
    }
}