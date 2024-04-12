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

int dp[505][505];
void solve() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else dp[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1;j <= b; j++) {
            
            for (int z = 1; z < i; z++) {
                dp[i][j] = min(dp[i][j], dp[z][j] + dp[i-z][j] + 1);
            }

            for (int z = 1; z < j; z++) {
                dp[i][j] = min(dp[i][j], dp[i][z] + dp[i][j-z] + 1);
            }

        }
    }
    // for (int i = 1; i <= a; i++) {
    //     for (int j = 1;j <= b; j++) {
    //         cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    //     }
    // }
    
    cout << dp[a][b] << endl;
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