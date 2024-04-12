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
vector<pair<int,int>>adj[100005];
bool vs1[100005];
bool vs2[100005];
int n,a,b;
bool ok = 0;
map<long long,bool>d;
ll dist = 0;
void bfs(int u, long long f) {
    if (vs1[u] == 1) return;
    vs1[u] = 1;
    // d[f] = 1;

    // cout << u << ' ' << f << endl;
    for (auto i : adj[u]) {
        if (vs1[i.fi] == 0 && i.fi != a) {
            d[(f^(i.se))] = 1;
            bfs(i.fi, (f^(i.se)));
        }
    }
}


void bfs2(int u, long long f) {
    if (vs2[u] == 1) return;
    vs2[u] = 1;
    if (d[f] == 1) {
        ok = 1;
        return;
    }
    // cout << u << ' ' << f << endl;
    
    for (auto i : adj[u]) {
        if (vs2[i.fi] == 0 && i.fi != b) {
            bfs2(i.fi, (f^(i.se)));
        }
    }
}
void solve() {
    ok = 0;
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        int x,y,z;
        cin >> x >> y >> z;    
        adj[x].pb({y,z});
        adj[y].pb({x,z});
        if ((x == a || x == b) && (y == a || y == b)) dist = z;
    }
    // d[0] = 1;
    d[dist] = 1;
    bfs(b,0);
    // for (auto i : d) {
    //     cout << i.fi << ' ' << i.se <<endl;
    // }
    // cout << endl << endl;
    bfs2(a,0);
    if (ok || d[0]) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    d.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vs1[i] = 0;
        vs2[i] = 0;
    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


class a {

}

a b = ...
a c = ...

  b = c++ ;
  