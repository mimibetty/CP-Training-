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
const int N = 100005;

struct LCA {
    int n, logn = 0, root = 1;
    vector<vector<int>> adj, p;
    vector<int> h;
 
    LCA(int n): n(n) {
        while ((1 << logn) <= n) logn++;
        p.assign(n + 1, vector<int>(logn + 1));
        h.resize(n + 1);
        adj.resize(n + 1);
    }
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int u, int par) {
        h[u] = h[par] + 1;
        p[u][0] = par;
        for (auto i: adj[u]) {
            if (i != par) dfs(i, u);
        }
    }
 
    void initJumps() {
        for (int j = 1; j <= logn; j++) {
            for (int i = 1; i <= n; i++) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }    
    }

    void setup() {
        dfs(1, 0);
        initJumps();
    }

    int getKthAnc(int n, int k) { // jump k nodes from n
        int node = n;
        for (int i = 30; i >= 0; i--) {
            if (p[node][i] != -1 && (1 << i) <= k) {
                node = p[node][i];
                k -= (1 << i);
            }
        }
        return node;
    } 
 
    int lca(int u, int v){
        if (h[u] < h[v]) swap(u, v);
        if (h[v] < h[u]) { // jump u to v
            for (int i = logn; i >= 0; i--) {
                if (h[p[u][i]] >= h[v]) u = p[u][i];
            }
        }
 
        for (int i = logn; i >= 0; i--) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i]; 
                v = p[v][i];
            }
        }
        
        while (u != v){
            u = p[u][0]; 
            v = p[v][0];
        }
 
        return u;
    }

    int dist(int u, int v) {
        return h[u] + h[v] - 2 * h[lca(u, v)];
    } 
};
vector<int> par(N,-1);
map<pair<int,int>,int> mp;
map<pair<int,int>,int> mp1;
vector<int> g[N];
vector <int> cnt (N,0);
void dfs(int u, int p) {
    par[u] = p;
    for (int v: g[u]) {
        if (v != p) {
            dfs(v,u);
        }
    }  
}
void dfs1 (int u, int p) {
    for (int v: g[u]) {
        if (v != p) {
            dfs1(v,u);
            mp1[{min(u,p),max(u,p)}] += mp1[{min(v,u),max(v,u)}];
        }
    }
}
void solve() {
    int n;cin >> n;
    LCA z(n);
    vector<pair<ll,ll>> cost(n+1);
    for (int i=1; i<n; i++) {
        int a,b;
        ll c1,c2; cin >> a >> b >> c1 >> c2;
        g[a].push_back(b);
        g[b].push_back(a);
        mp[{min(a,b),max(a,b)}] = i;
        cost[i] = {c1,c2};
        z.addEdge(a,b);
    }
    z.setup();
    dfs(1,0);
    for (int i=2; i<=n; i++) {
        int v = z.lca(i-1,i);
        mp1[{min(i,par[i]),max(i,par[i])}] += 1;
        mp1[{min(i-1,par[i-1]),max(i-1,par[i-1])}]+=1;
        mp1[{min(v,par[v]),max(v,par[v])}] -=2;
    }
    
    // for (int i=1; i<=n; i++) {
    //     if (g[i].size() == 1) {
    //         int u = i;
    //         int v = par[i];
    //         while (par[v] != 0) {
    //             if (min(v,par[v]) == 1 && max(v,par[v])==2 ) {
    //                 cout <<"#" << u << ' ' << v << ' ' << mp1[{min(v,u),max(v,u)}] << endl;
    //             }
    //             mp1[{min(v,par[v]),max(v,par[v])}] += mp1[{min(v,u),max(v,u)}];
    //             u = v;
    //             v = par[v];
    //         }
    //     }
    // }
    dfs1(1,0);
    ll ans = 0;
    for (auto x: mp1) {
        if (x.fi.fi != 0) {
            // cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se << ' ';
            ans += min(1ll* cost[mp[x.fi]].se,1ll*x.se * cost[mp[x.fi]].fi);
            // cout << min(cost[mp[x.fi]].se,x.se * cost[mp[x.fi]].fi) <<endl;
        }
    }
    cout << ans;
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
    while (t--)    
    solve();
    
    return 0;
}

 