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

int a[200005];
vector<int>adj[200005];
int cost[200005];
int trace[200005];
pair<int,int>x[200005];
bool vs[200005];
vector<int>d[200005];
void dfs(int u, int p) {
    
    cost[u] = 1;
 
    for (auto i : adj[u]) {
        if (i == p) continue;
        dfs(i,u);
        cost[u] += cost[i];
    }

}
 
void solve() {
    int n;
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        trace[i] = a[i];
        if (a[i] == i) root = i;
        if (a[i] != i) {
            adj[i].pb(a[i]);
            adj[a[i]].pb(i);
        }
    }

    dfs(root,0);
    for (int i = 1; i <= n; i++) {
        x[i] = {cost[i],i};
    }
    sort(x + 1, x + 1 + n);

    vector<int>ans;
    int cs = 0;
    for (int i = 1; i <= n; i++) {
        // cout << x[i].fi << ' ' << x[i].se << endl;
        if (vs[x[i].se] == 1) continue;

        cs++;
        int cnt = 0;
        int tar = x[i].se;
        while(vs[tar] == 0) {
            vs[tar] = 1;
            cnt++;
            d[cs].pb(tar);
            tar = trace[tar];
        }
        ans.pb(cnt);
    }

    cout << ans.size() << endl;

    for (int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << endl;
        for (int j = d[i+1].size() - 1; j >= 0; j--) cout << d[i+1][j] << ' ';
        // for (auto j : d[i+1]) cout << j << ' ' ;
        cout << endl;
    }

    cout << endl;


    for (int i = 1; i <= n; i++) {
        vs[i] = 0;
        adj[i].clear();
        cost[i] = 0;
    }
    for (int i = 1; i <= cs; i++) {
        d[i].clear();
    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}