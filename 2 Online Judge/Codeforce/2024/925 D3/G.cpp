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


const int modd = 998244353;
void solve() {
    int c1,c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    // cout <<c1 << ' ' << c2 << endl;
    vector<vector<vector<vector<vector<int>>>>> dp(c1 + 1, vector<vector<vector<vector<int>>>>(c2 + 1, vector<vector<vector<int>>>(c3 + 1, vector<vector<int>>(c4 + 1, vector<int>(5)))));
    // cout <<c1 << ' ' << c2 << endl;
        
    dp[0][0][0][1][4] = 1;
    dp[0][0][1][0][3] = 1;
    dp[0][1][0][0][2] = 1;
    dp[1][0][0][0][1] = 1;
   
    for (int j1 = 0; j1 <= c1; j1++) {
        for (int j2 = 0; j2 <= c2; j2++) {
            for (int j3 = 0; j3 <= c3; j3++) {
                for (int j4 = 0; j4 <= c4; j4++) {
                    if (j1 - 1 >= 0) {
                        dp[j1][j2][j3][j4][1] += dp[j1 - 1][j2][j3][j4][2] + dp[j1 - 1][j2][j3][j4][4];
                        dp[j1][j2][j3][j4][1] %= modd;                        
                    }

                    if (j2 - 1 >= 0) {
                        dp[j1][j2][j3][j4][2] += dp[j1 ][j2 - 1][j3][j4][1] + dp[j1 ][j2 - 1][j3][j4][3];
                        dp[j1][j2][j3][j4][2] %= modd;

                    }
                    if (j3 - 1 >= 0) {
                        dp[j1][j2][j3][j4][3] += dp[j1][j2][j3 - 1][j4][1] + dp[j1][j2][j3 - 1][j4][3];
                        dp[j1][j2][j3][j4][3] %= modd;
                        
                    }
                    if (j4 - 1 >= 0) {
                        dp[j1][j2][j3][j4][4] += dp[j1][j2][j3][j4 - 1][2] + dp[j1][j2][j3][j4 - 1][4];
                        dp[j1][j2][j3][j4][4] %= modd;
                        
                    }
                    
                    
                }
            }
        }
    }    
    ll x = dp[c1][c2][c3][c4][1] + dp[c1][c2][c3][c4][2] + dp[c1][c2][c3][c4][3] + dp[c1][c2][c3][c4][4]; 
    x %= modd;
    cout << x << endl;
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