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

ll a[200005];
ll ps[200005];

ll dp[200005][4];

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
        ps[i] = a[i] + ps[i-1];
    }
    if (n == 1) {
        cout << a[1] << endl;
        return 0;
    }   
    for (int i = 1; i <= n; i++) {
        dp[i][1] = -1e18;
        dp[i][2] = -1e18;
        dp[i][0] = ps[i];
    }
    dp[0][1] = 0;
    dp[0][2] = 0;

    // for (int z = 1; z <= 2; z++) {
    //     // cout << "Z  " << z << endl;
    //     ll xx = -1e18;
    //     for (int i = 1; i <= n; i++) {
    //         dp[i][z] = dp[i-1][z] + a[i];
    //         for (int j = 1; j <= i; j++) {
    //             // cout << i << ' ' << j << ' ' << dp[j-1][z-1] - (ps[i] - ps[j-1]) << endl;
    //             dp[i][z] = max(dp[i][z],dp[j-1][z-1] - (ps[i] - ps[j-1]));
    //             xx = max(xx, dp[j-1][z - 1] + ps[j - 1]);
    //         }

    //         cout << z << ' ' << i << ' ' << dp[i][z] << ' ' << xx << endl; 
    //     }
    // }
    // dp[i][z] = max(dp[i][z],(dp[j-1][z-1] + ps[j-1]) - ps[i] );
    ll dd = -1e18;
    for (int z = 1; z <= 2; z++) {
        dd = dp[0][z-1];        
        for (int i = 1; i <= n; i++) {
            dp[i][z] = dp[i-1][z] + a[i];
            dd = max(dd, dp[i-1][z-1] + ps[i-1]);
            dp[i][z] = max(dp[i][z],dd - ps[i]);
            // cout << z << ' ' << i << ' ' << dp[i][z] << ' ' << dd << endl;
        }
    }

    cout << dp[n][2] << endl;
    

    return 0;
}
