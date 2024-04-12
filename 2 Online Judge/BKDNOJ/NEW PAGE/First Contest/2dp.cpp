#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}
long long mod = 1e9+7;

ll n;
ll cnt;
void backtrack(int stt, int s1, int s2, int s3) {
    if (stt == n + 1) {
        if (s1 % 3 == 0 && s2 % 2 == 0) cnt++;
        cnt %= mod;
        return;
    }

    backtrack(stt + 1, s1 + 1, s2 ,s3);
    backtrack(stt + 1, s1 , s2 + 1,s3);
    backtrack(stt + 1, s1, s2 ,s3 + 1);
    return;
}

ll dp[1000005][4][3];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int z = 0; z <= 1; z++) {
                // vt i = 3
                if (j == 0) dp[i][j][z] += dp[i-1][2][z];
                else dp[i][j][z] += dp[i-1][j-1][z];
                
                dp[i][j][z] %= mod;

                // vt i = 2
                if (z == 0) dp[i][j][z] += dp[i-1][j][1];
                else dp[i][j][z] += dp[i-1][j][z - 1];
                dp[i][j][z] %= mod;

                // vti = 0 
                dp[i][j][z] += dp[i-1][j][z];         
                dp[i][j][z] %= mod;   
            }
        }
    }
    // dp[n][0][0] = dp[n-1][2][0] + dp[n-1][0][1] + dp[n-1][0][0]


    // dp[n][0][1] = dp[n-1][2][0] + dp[n-1][0][0] + dp[n-1][0][1]


    // dp[n][1][0] = dp[n-1][0][0] + dp[n-1][1][1] + dp[n-1][1][0]


    // dp[n][1][1] = dp[n-1][0][1] + dp[n-1][1][0] + dp[n-1][1][1]


    // dp[n][2][0] = dp[n-1][1][0] + dp[n-1][2][1] + dp[n-1][2][0]

    // dp[n][2][1] = dp[n-1][1][1] + dp[n-1][2][0] + dp[n-1][2][1]
    cout << dp[n][0][0] << endl;
    // backtrack(1,0,0,0);
    // cout << cnt << endl;
    return 0;
}