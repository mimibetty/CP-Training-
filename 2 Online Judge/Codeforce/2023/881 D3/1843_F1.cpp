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
int maxx[200005];
int minn[200005];
int vs[200005];

int preMax[200005];
int preMin[200005];

struct ans {
    int u,v,distance;
    ans(int uu, int vv, int kk) {
        u = uu;
        v = vv;
        distance = kk;
    }
};

void dfs(int u, int v, int summ) {
    // cout << "U  V  " << u << ' '<< v << endl;
    if (vs[u] == 1) {
        return;
    }
    vs[u] = 1;

    for (auto i : adj[u]) {
        if (i.fi != v && vs[i.fi] == 0) {
            summ += i.se;
            maxx[i.fi] = max({maxx[u], summ - preMin[u]});
            minn[i.fi] = min({minn[u], summ - preMax[u]});
            preMax[i.fi] = max(preMax[u],summ);
            preMin[i.fi] = min(preMin[u],summ);
            
            // cout << "NODE: " << i.fi << ' ' << "W:  " << i.se << endl; 
            // cout <<summ <<  ' ' <<  maxx[i.fi] << ' ' << minn[i.fi] << ' ' << preMax[i.fi] << ' ' << preMin[i.fi] << "  Par: " << u << ' '<< v << endl;
            dfs(i.fi,u,summ);            
            summ -= i.se;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    int cnt = 1;
    vector<ans>f;
    for (int i = 1; i <= n; i++) {
        char z;
        int u,v,k;
        cin >> z;
        if (z == '+') {
            cin >> u >> v;
            cnt++;
            adj[cnt].pb({u,v});
            adj[u].pb({cnt,v});
        }
        else {
            cin >> u >> v >> k;
            ans x(u,v,k);
            f.pb(x);
        }
    }
    maxx[1] = 1;
    preMax[1] = 1;
    preMin[1] = 0;
    dfs(1,0,1);

    // return;
    // cout << endl << endl;
    for (auto i : f) {
        // cout << i.u << ' ' << i.v << ' ' << i.distance << endl;
        // cout << minn[i.v] << ' ' << maxx[i.v] << endl;
        if (i.distance >= minn[i.v] && i.distance <= maxx[i.v]) {
            cout << "Yes" << endl;
        }
        else cout << "NO" << endl;
    }
    // for (int i = 1; i <= 6; i++) {
    //     cout << i << ' ' << preMax[i] << ' ' << preMin[i];
    //     cout << ' '<< maxx[i] <<' ' << minn[i] << endl;
    // }

    for (int i = 1; i <= cnt; i++) {
        adj[i].clear();
        minn[i] = 0;
        maxx[i] = 0;
        vs[i] = 0;
        preMax[i] = 0;
        preMin[i] = 0;
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
