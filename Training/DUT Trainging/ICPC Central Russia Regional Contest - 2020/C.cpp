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

vector<int>adj[100005];
int vs[100005];
vector<pii>ed[10];
void solve() {
    int n,m,u,v;
    cin >> n >> m >> u >> v;
    for (int i = 1; i <=m; i++) {
        int x,y,w;
        cin >> x >> y >> w;
        ed[w].pb({x,y});
    }

    int ok = -1;
    for (int t = 1; i <= 7; t++) {
        for (auto i : ed[t]) {
            adj[i.fi].pb(i.se);
            adj[i.se].pb(i.fi);            
        }
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
       
    return 0;
}