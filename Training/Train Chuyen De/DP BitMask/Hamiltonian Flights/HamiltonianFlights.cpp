/*
link submit: https://cses.fi/problemset/task/1690
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define bit(n,i)  ((n>>i) & 1) 
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

const int MOD = 1e9 + 7;
const int MAX_N = 20;
ll dp[1 << MAX_N][MAX_N];
vector<int> adj[MAX_N];
int d[MAX_N][MAX_N];
int n, m;

bool ps[1 << MAX_N];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;

        adj[v].push_back(u);

    }

    ps[0] = 1;
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int Pos_now = 0; Pos_now < n; Pos_now++) {
            if (bit(mask, Pos_now) == 0) continue; 

            int pre_mask = mask - (1 << Pos_now);       
            
            if (ps[pre_mask] == 0) continue;

            for (auto Pos_before : adj[Pos_now]) {
                if (bit(pre_mask,Pos_before) == 1) {
                    dp[mask][Pos_now] += dp[pre_mask][Pos_before];
                    while (dp[mask][Pos_now] > MOD) {
                        dp[mask][Pos_now] -= MOD;
                    }
                    // dp[mask][Pos_now] %= MOD;
                }
            }

            if(dp[mask][Pos_now] > 0) {
                ps[mask] = 1;
            }
        }
    }

    cout << dp[(1 << n) - 1][n-1] << endl;
    return 0;
}