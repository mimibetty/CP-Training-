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

int a[200005];
int dp[200005];
int n;
void resett() {
    for (int i = 1; i <= n; i++) dp[i] = 1e9;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    resett();
    dp[n] = 1;
    dp[n+1] = 0;
    for (int i = n-1; i >= 1; i--) {
        // for (int j = i+1; j <= min(n + 1,i + a[i]); j++) {
        //     dp[i] = min(dp[i], j-i + dp[j]);
        // }
        dp[i] = dp[i+1] + 1;
        if (i + a[i] <= n) {
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
        }

    }
    cout <<dp[1] << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << ' ';
    // }
    // EL;


}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}