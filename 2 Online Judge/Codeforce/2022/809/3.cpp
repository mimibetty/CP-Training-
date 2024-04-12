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

long long dp[100005];
long long a[100005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 1) {
        long long res = 0;
        for (int i = 2; i <= n; i += 2) {
            long long x = max(a[i-1], a[i+1]);
            if (a[i] <= x) {
                res =  res + (x+1) - a[i];
            }
        }
        cout << res <<endl;
    } 
    else {
        for (int i = 2; i <= 3; i++) {
            long long x = max(a[i-1], a[i+1]);
            if (a[i] <= x) {
                dp[i] = (x+1) - a[i];
            }
        }

        for (int i = 4; i < n; i++) {
            ll temp = 0;
            long long x = max(a[i-1], a[i+1]);
            if (a[i] <= x) {
                temp += (x+1) - a[i];
            }
            if (i % 2 == 1) {
                dp[i] = min(dp[i-2], dp[i-3]) + temp;
            }  
            else {
                dp[i] = dp[i-2] + temp;
            }
        }
        
        cout << min({dp[n-1], dp[n-2]}) << endl;
        // for (int i = 1; i <= n; i++) cout << i <<' ' <<dp[i] << endl;
        for (int i = 1; i <= n; i++) dp[i] = 0;
    }


}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}