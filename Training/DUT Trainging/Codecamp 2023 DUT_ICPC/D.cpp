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

int dp[1000005];
int trace[1000005];
void solve() {
    int n;
    cin >> n;
    cout << dp[n] << endl;;
    int x = n;
    vector<int>ff;
    while (x >= 1) {
        if (trace[x] == 3) {
            while (x % 3 != 0) {
                ff.pb(x);
                x--;
            }
            ff.pb(x);
            x/=3;
        } 
        else if (trace[x] == 2) {
            if (x % 2 != 0) {
                ff.pb(x);
                x--;
            }
            ff.pb(x);
            x/=2;
        }
        else {
            ff.pb(x);
            x--;
        }
    }
    reverse(All(ff));
    for (auto i : ff) cout << i << ' ';
    cout <<endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = min({dp[i/2] + i % 2 + 1, dp[i/3] + i % 3 + 1,dp[i-1] + 1});
        if (dp[i] == dp[i/2] + i % 2 + 1) {
            trace[i] = 2;
        }
        if (dp[i] == dp[i/3] + i % 3 + 1) {
            trace[i] = 3;
        }
        if (dp[i] == dp[i-1] + 1) {
            trace[i] = 1;
        }
    }
    trace[1] = 1;
    trace[2] = 2;
    trace[3] = 3;
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}