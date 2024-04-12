#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

long long mod = 987654321;

long long pw(long long a,long long b) {
    if (b == 0) return 1;
    long long q = pw(a,b/2);
    if (b % 2 == 0) return q * q % mod;
    else return q * q % mod * a % mod;

}

long long fact[1000009], f[1000009];

long long lagrange(long long n, int k) {
    if (n <= k) return f[n];

    // use prefix and suffix if n - i can be 0
    long long tu = 1;
    for (int i = 0; i <= k; i++) {
        tu *= (n - i);
        tu %= mod;
    }

    long long res = 0;
    for (int i = 0; i <= k; i++) {
        long long mau = (n - i) * fact[i] % mod * fact[k - i] % mod;
        if ((k - i) % 2) mau *= -1;
        mau = (mau % mod + mod) % mod;

        res += f[i] * tu % mod * pw(mau, mod - 2) % mod;
        res %= mod;
    }
    return res;
}

long long lagrange11(vector<long long> &f, int n, int k) {
    if (n <= k) return f[n];

    // use prefix and suffix if n - i can be 0
    long long tu = 1;
    for (int i = 0; i <= k; i++) {
        tu *= (n - i);
        tu %= MOD;
    }

    long long res = 0;
    for (int i = 0; i <= k; i++) {
        long long mau = (n - i) * fact[i] % MOD * fact[k - i] % MOD;
        if ((k - i) % 2) mau *= -1;
        mau = (mau % MOD + MOD) % MOD;

        res += f[i] * tu % MOD * pw(mau, MOD - 2) % MOD;
        res %= MOD;
    }
    return res;
}

long long lagrangeSelf(vector<pair<long long, long long>>&f, long long n, long long k) {
     if (n <= 9) return 0;
     long long res = 0;
     for (int j = 0; j < f.size(); j++) {
        long long tmp = f[j].se;
        for (int i = 0; i < f.size(); i++) {
            tmp *= (n - f[i].fi);   
        }

        for (int i = 0; i < f.size(); i++) {
            if (i == j) continue;
            tmp /= (f[j].fi - f[i].fi);   
        }
        res += tmp;
        res %= mod;
     }

     return res;
    // use prefix and suffix if n - i can be 0
    // long long tu = 1;
    // for (int i = 0; i <= k; i++) {
    //     tu *= (n - i);
    //     tu %= MOD;
    // }

    // long long res = 0;
    // for (int i = 0; i <= k; i++) {
    //     long long mau = (n - i) * fact[i] % MOD * fact[k - i] % MOD;
    //     if ((k - i) % 2) mau *= -1;
    //     mau = (mau % MOD + MOD) % MOD;

    //     res += f[i] * tu % MOD * pw(mau, MOD - 2) % MOD;
    //     res %= MOD;
    // }
    // return res;


   
}


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    f[0] = 1;
    f[1] = 0;
    f[2] = 0;
    f[3] = 1;
    f[4] = 4;
    for (int i = 5; i <= 30; i++) {
        f[i] = 5*f[i-1] -10*f[i-2] + 10*f[i-3] - 5*f[i-4] + f[i-5];
        f[i] %= mod;
    }
   

    fact[0] = 1;
    for (int i = 1; i <= 100000 + 1; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    vector<pair<long long, long long>> ff;
    ff.pb({3,0});
    ff.pb({4,4});
    for (int i = 5; i <= 9; i++) {
        ff.pb({i,f[i]});
    }
    // for (auto i : ff) cout << i.fi << ' ' << i.se << endl;
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long res = lagrangeSelf(ff,n,7) ;
        res = (res%mod + mod) % mod;
        cout <<n << ' ' << res << endl;
    }
    return 0;
}