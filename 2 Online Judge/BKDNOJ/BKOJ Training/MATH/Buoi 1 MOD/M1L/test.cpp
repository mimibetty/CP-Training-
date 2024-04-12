#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
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
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
int const MaxN = 1000005;
int a[1005];
int trace[MaxN];
// long long fact[MaxN];
// long long inv[MaxN];
const int lim = 1e6 ;
 
ll combi[1005][1005];
 
long long pw(long long a, long long b, long long mod) {
    if (b == 1) return a;
    if (b == 0) return 1;
    long long q = pw(a, b/2, mod) % mod;
    if (b % 2 == 0) return q%mod * q%mod;
    else return q%mod * q%mod * a%mod; 
}
 
// long long combi(long long a,long long b, long long mod) {
//     if (a >= b) return fact[a]%mod * inv[b]%mod * inv[a-b]%mod;
//     return 0; 
// }
 
void sieve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (trace[i] == 0) 
            for (int j = i * i; j <= n; j+= i)
                if (trace[j] == 0) trace[j] = i;
    }
 
    for (int i = 2; i <= n; i++) if (trace[i] == 0) trace[i] = i;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    sieve(1e6);
    combi[0][0] = 1;
 
    for (int i = 1; i <= 1000; i++) {
        combi[i][0] = 1;
        for (int j = 1; j <= i ;j++) {
            combi[i][j] = (combi[i-1][j-1]%(MOD-1)) + (combi[i-1][j]%(MOD-1));
            combi[i][j] %=(MOD-1);
            // cout << i << ' ' << j << ' '<< combi[i][j] << endl;
        }
    }
 
    // fact[0] = 1;
  //   inv[0] = 1;
 
  //   for (long long i = 1; i <= lim; i++) {
  //       fact[i] = i * fact[i-1] % (MOD-1);
  //   }
 
  //   inv[lim] = pw(fact[lim],MOD-2,MOD);
  //   for (long long i = (lim-1); i >= 1; i--) {
  //       inv[i] = inv[i+1] * (i+1) % (MOD-1);
  //   }
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll snt = 0, hopso = 0;
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (trace[a[i]] == a[i]) snt++;
            else hopso++;
        }
 
        ll index_num = pw(2,hopso,MOD-1)%(MOD-1);
        // cout << index_num << endl;
        for (ll i = 0; i <= snt; i++) {
            ll somu = (combi[snt][i]%(MOD-1)) * index_num;
            somu %= (MOD-1);
 
            ans *= pw((i+2), somu, MOD);
            ans %= MOD;
            // cout << "STT" << i << ' ' <<ans << endl;
            // cout << pw((i+2), somu, MOD) << ' ' <<combi[snt][i]%(MOD-1)<< ' '<< somu << endl; 
            // cout << endl;
        }
 
        cout << ans << endl;
        // ans = (snt + 2) ^ combi(snt, tong snt,mod-1)* pw(2,hopso,mod-1)
    }
    return 0;
}