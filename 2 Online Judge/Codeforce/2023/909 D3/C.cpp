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
long long a[200005];
long long dp[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i<= n; i++) {
        cin >> a[i];
    }
    ll res = -1e18;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = a[i];
        if (abs(a[i] + a[i-1]) % 2 == 1) {
            dp[i] = max({a[i], dp[i-1] + a[i]});
        }
    }    
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
    }
    // long long minOdd = 1e18;
    // long long minEven = 1e18;
    
    // for (int i = 1; i <= n;i++) {
    //     res = max(res, a[i]);
    //     if (abs(a[i]) % 2 == 0) {
    //         res = max(res, ps[i] - minOdd);
    //         minEven = min(minEven, ps[i]);
    //     } 
    //     else {
    //         res = max(res, ps[i] - minEven);
    //         minOdd = min(minOdd, ps[i]);
    //     }


    // }
    // cout << res <<endl;
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