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

struct inf {
    long long u,v,w;

};

bool cmp(inf a, inf b) {
    return a.w < b.w;
}

int n,m;
int root[1000005];
inf a[1000005];

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
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = -1;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }

    sort(a + 1, a + 1 + m,cmp);
    long long res = 0;
    
    for (int i = 1; i <= m; i++) {
        if (findRoot(a[i].u) != findRoot(a[i].v)) {
            res += a[i].w;
            merge(a[i].u, a[i].v);
        }
    }
    cout << res << endl;
    // for (int i = 1; i <= m; i++) cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w <<endl;
    return 0;
}