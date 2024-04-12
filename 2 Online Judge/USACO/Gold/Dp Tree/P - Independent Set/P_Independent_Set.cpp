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

const ll modd = (1e9 + 7);
vector<int>adj[100005];
ll dp[100005][3];

void dfs(int u, int p) {  
    dp[u][0] = dp[u][1] = 1; 

    for (auto i : adj[u]) {
        if (i == p) continue;

        dfs(i,u);
        dp[u][1] *= dp[i][0];
        dp[u][1] %= modd;

        dp[u][0] *= (dp[i][0] + dp[i][1]) % modd;
        dp[u][0] %= modd; 
    }
}
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2 << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v; 
        adj[u].pb(v);
        adj[v].pb(u);
    }


    dfs(1,-1);
    ll res = dp[1][0] + dp[1][1];
    res %= modd;
    cout << res << endl;
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