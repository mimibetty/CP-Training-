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

int n,t;
int root[100005];
int number,maxval;

int findRoot(int u) {
    while (root[u] >= 0) {
        u = root[u];
    } 
    return u;
}

void add(int u, int v) {
    u = findRoot(u);
    v = findRoot(v);

    if (u == v) return;

    if (root[u] > root[v]) swap(u,v);

    root[u] += root[v];
    root[v] = u;
    number--;
    maxval = max(maxval, abs(root[u]));
    return;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> t;
    maxval = 1;
    number = n;
    for (int i = 0; i <= n; i++) root[i] = -1;

    while (t--) {
        int u,v;
        cin >> u >> v;
        // cout << u << ' ' << v << endl;
        add(u,v);
        cout << number << ' ' << maxval << endl;
    }
    return 0;
}