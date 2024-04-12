

/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}
const long long MOD = 987654321;
long long fact[100];
// degree = k, find f[n]
// O(k) - formula with i = 0 -> k
long long pw(long long n, long long k) {
    if (k == 0) return 1;
    long long q = pw(n, k/2);
    if (k % 2 == 0) {
        return q * q % MOD;
    }
    else return q * q % MOD * n % MOD;
}

long long lagrange(vector<long long> &f, int n, int k) {
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

void solve() {
     // With polynomial degree n:
    // A(x) = sum (A(j) * (mul (x - xk) / (xj - xk))) (j: 1 -> n + 1, k != j)
    // 1^k + 2^k + ... + n^k -> deg = k + 1
    long long n;
    cin >> n;
    int k = 4;

    vector<long long>f(7);
    f[0] = f[1] = f[2] = 0;
    f[3] = 1;
    f[4] = 4;
    f[5] = 11;
    f[6] = 25; 
    cout << lagrange(f,n,k) << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    fact[0] = 1;

    for (int i = 1; i <= 50 + 1; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
   
    return 0;
}