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
int dd[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        dd[a[i]] = -99999999;
    }
    // for (int i = 1; i <= n; i++) {
    //     dp[i] = dp[i-1];
    //     for (int j = 1; j < i; j++) { 
    //         if (a[i] == a[j]) {
    //             dp[i] = max(dp[i], dp[j] + i - j + 1);
    //         }
    //     }
    //     cout << dp[i] << ' ';
    // }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        // if (dd[a[i]]) {
            dp[i] = max(dp[i], dd[a[i]] + i + 1);
        // }
        dd[a[i]] = max(dd[a[i]], dp[i - 1] - i);
        // cout <<i << ' ' << dp[i] << ' ' << dd[a[i]] << endl;
    }
    
    cout << dp[n] << endl;
    for (int i = 0; i <= n; i++) {
        dp[i] = 0 ;
        dd[a[i]] = 0;
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
    while (t--) {
        solve();
    }
    return 0;
}