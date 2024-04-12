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


void solve() {
  int t,n;
  while (1) {
    cin >> t;
    if (t == 0) return;

    cin >> n;
    vector<int>a(n + 1);
    // cout << t << ' ' << n << endl;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
    }

    vector<int>dp(t + 1);
    vector<int>trace(t + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= 0; j--) {
            if (dp[j]) continue;
            if (j - a[i] >= 0) {
                if (dp[j - a[i]] == 1) {
                    trace[j] = a[i];
                    dp[j] |= dp[j-a[i]];
                }
            }
        }
    }
    // for (int i = 0; i <= t; i++) {
    //     cout << dp[i] << ' ';
    // }
    // EL;
    int val  = 0;
    int res = 0;
    for(int i = t; i >= 0; i--) {
        if (dp[i] == 1) {
            val = i;
            res = i;
            // cout << i << endl;
            break;
        }
    }
    for (int i = 1; i <= t; i++) {
        cout << i << ' ' << trace[i] << endl;
    }
    EL;EL;
    vector<int> morder;
    while (val > 0) {
        morder.pb(trace[val]);
        // cout << trace[val] << ' ';
        // cout << trace[val] << ' ' << val << endl;;
        val -= trace[val];
    }
    reverse(All(morder));
    for (auto i : morder) cout << i << ' ';
    cout << res << endl;
    
  }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

 
    solve();
    
    return 0;
}