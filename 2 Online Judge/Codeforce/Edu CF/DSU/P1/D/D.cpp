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
string s[150005];
int u[150005], v[150005];
int root[50005];

int findRoot(int u) {
    while (root[u] >= 0) {
        u = root[u];
    }
    return u;
}

void merge(int u, int v) {
    u = findRoot(u);
    v = findRoot(v);

    if (u == v) return;

    if (root[u] > root[v]) swap(u,v);

    root[u] += root[v];
    root[v] = u;
    return;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m,t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) root[i] = -1;


    for (int i = 1; i <= m; i++) {
        int x,y;
        cin >> x >> y;
    }

    for (int i = 1; i <= t; i++) {
        cin >> s[i] >> u[i] >> v[i];
    }

    vector<string>res;
    for (int i = t; i >= 1; i--) {
        if (s[i] == "ask") {
            if (findRoot(u[i]) == findRoot(v[i])) res.pb("YES");
            else res.pb("NO");
        }
        else {
            if (findRoot(u[i]) != findRoot(v[i])) merge(u[i], v[i]); 
        }
    }

    reverse(res.begin(),res.end());
    for(auto i : res) cout << i << endl;
    return 0;
}