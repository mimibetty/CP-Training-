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

long long a[100005];
long long dp[100005][55];
long long p2[35];
void solve() {
    long long n,k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

      for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 32; j++) dp[i][j] = -1e18;
    }
    for (int i =  1; i <= n; i++) {
        for (int j = 0; j <= 32; j++) {
            dp[i][j] = max(dp[i-1][j] + (a[i]/p2[j]) - k, dp[i][j]);
            
            if (j-1>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]/(p2[j])); 
            if (j == 32) {
                dp[i][j] = max({dp[i][j], dp[i-1][j]});
            }
        }
    }
    long long res = -1e18;
    for (int i = 0; i <= 32; i++) res = max(res, dp[n][i]);
        cout << res <<endl;
  
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    p2[0] = 1; 
    for (int i = 1; i <= 32; i++) {
        p2[i] = p2[i-1] * 2;
    }
    // cout <<log(4) << endl;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}