#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
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
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

vector<int>adj[200005];
bool vs[200005];
void dfs(int u, int v) {
    vs[u] = 1;
    for (auto i : adj[u]) {
        if (i == v) continue;

        if (vs[i] == 1) continue;
        dfs(i,u);
    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cnt = 0;
    vector<int>res;
    for (int i = 1; i <= n; i++) {
        if (vs[i] == 0) {
            dfs(i,0);
            cnt++;
            res.pb(i);
            continue;
        }
    }
    cnt = cnt - 1;
    cout << cnt << endl;

    for (int i = 1; i <= cnt; i++) {
        cout << res[i-1] << ' ' << res[i] << endl;
    }
    return 0;
}