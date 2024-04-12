#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
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
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
const int maxN = 1e5 + 5;
vector<int>adj[maxN];
int cost[maxN];
int par[maxN];
int res[maxN];
int n;
int cnt[maxN];

void dfs(int u, int p) {
    for (auto i : adj[u]) {
        if (i == p) continue;
        cost[i] = cost[u] + 1;
 
        dfs(i, u);
 
    }
}
 
void solve(int root) {
    cost[root] = 0;
    dfs(root,0);
 
    for (int i = 1; i <= n; i++) {
        res[i] = max(res[i], cost[i]);
        // cout << i << ' ' << cost[i] << endl;
    }
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
 
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);           
    }
    dfs(1,0);
 
 
    int root1 = 1;
    int root2 = 1;
 
    for (int i = 2; i <= n; i++) {
        if (cost[i] > cost[root1]) root1 = i; 
    }
 
    cost[root1] = 0;
 
    dfs(root1,0);
    for (int i = 1; i <= n; i++) {
        if (cost[root2] < cost[i]) root2 = i;
    }
 
    solve(root1);
    solve(root2);
 
    // for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    // cout << endl;
    int f = 1;
    for (int i = 1; i <= n; i++) {
        cnt[res[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        f += cnt[i-1];
        f = min(f,n);
        cout << f << ' ';
    }
    return 0;
}