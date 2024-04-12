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

vector<pii>adj[200005];
ll x[200005];
bool d[200005];
bool ok;
void dfs(int u,int p) {
    // if (d[u] == 0) {
    //     d[u] = 1;
    //     x[u] = 2;
    // }
    for (auto i : adj[u]) {
        if (d[i.fi] == 0) {
            d[i.fi] = 1;
            x[i.fi] = i.se + x[u];
            dfs(i.fi,u);
        }
        // else {
        //     if (x[i.fi] != x[u] + i.se) {
        //         ok = 0;
        //         cout << i.fi << ' ' << u << ' ' << x[i.fi] << ' '
        //         << x[u] +i.se << endl;
        //         return;
        //     }
        // }
    }
}
struct cc{
    ll x,y,z;
};
void solve() {
    int n,m;
    cin >> n >> m;
    ok = 1;
    vector<cc>checkk;
    for (int i = 1; i <= m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,-1*c});
        checkk.pb({a,b,c});
        checkk.pb({b,a,-c});
        
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            dfs(i,0);
        }
    }
    // EL;
    // for (int i = 1; i <= n; i++) {
    //     cout << x[i] << ' ';
    // }
    // EL;
    

    for (auto i : checkk) {
        if (x[i.x] != x[i.y] - i.z) {
            ok = 0;
            // cout << i.x << ' ' << i.y << ' '<<i.z << ' ' << x[i.x] << ' '<<x[i.y] << endl;  
        } 
    }
    if (ok) {
        cout << "YES" << endl;
    }
    else cout <<"NO" << endl;

    
    for (int i = 1;i <= n; i++) {
        adj[i].clear();
        d[i] = x[i] = 0;
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
    while (t--)   
    solve();
    
    return 0;
}