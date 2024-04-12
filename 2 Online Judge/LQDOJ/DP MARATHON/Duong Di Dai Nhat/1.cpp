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

int d[100005];
vector<int>adj[100005];

int dp(int u) {
    if (d[u] != -1) return d[u];

    for (auto i : adj[u]) {
        d[u] = max(d[u], dp(i) + 1);
    }

    return d[u];
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
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) d[i] = 0;
        else d[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        d[i] = dp(i);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ' << d[i] << endl;
        res = max(res,d[i]);
    }
    cout << res <<endl;
    return 0;
}