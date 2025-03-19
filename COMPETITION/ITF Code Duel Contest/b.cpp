/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

int a[1000005];
int dp[1000005];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1e9;
    }

    dp[0] = 0;
    dp[n+1] = 1e9;
    a[n+1] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n+1; i++) {
        if (a[i] == 1) continue;

        if (i - 1 >= 0 ) {
            if (a[i-1] == 0) dp[i] = min(dp[i], dp[i-1] + 1);
        }
        if (i - 2 >= 0) {
            if (a[i-2] == 0) dp[i] = min(dp[i], dp[i-2] + 1);
        }
    }


    // for (int i = 1; i <= n + 1; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    if (dp[n+1] > 1e7) {
        cout << -1 <<endl;
    }
    else cout << dp[n+1] ;
    return 0;
}