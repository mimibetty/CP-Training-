#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,int> pii;
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
 
ll n, x;
  
ll a[105][5]; // 1 la kg  , 2 la tien
ll dp[50005];

// ll dp(ll val) {
//     if (val <= 0) return 0;
//     if (check[val] == 1) return d[val];

//     for (ll i = 1; i <= n; i++) {
//         d[val] = min(d[val], dp(x - a[i][1]) + a[i][2]);
//     }

//     check[val] = 1;
//     return d[val];
// }
int main() {
     freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    cin >> n >> x;
    
    for (int i = 1; i <= n; i++) cin >>a[i][1] >> a[i][2];

    for (int i = 1; i <= 50000; i++) dp[i] = 1e18;
    dp[0] = 0;
    
    for (int i = 1; i <= 50000; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - a[j][1] <= 0) {
                dp[i] = min(dp[i], a[j][2]);
                continue;
            }
            dp[i] = min(dp[i], dp[i-a[j][1]] + a[j][2]);            
        }
        // cout << i << ' ' << dp[i] << endl;
    }
    ll res = 1e18;
    for (int i = x; i <= 50000; i++) res =min(res, dp[i]);
    cout << res;
    // cout << dp[x];
    return 0;
}