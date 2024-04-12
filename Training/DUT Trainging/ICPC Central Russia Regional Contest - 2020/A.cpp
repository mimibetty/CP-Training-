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
int kc[100005];
int sub[100005];
int parr[100005];
void dfs(int u, int par) {
    sub[u] = 1;
    for (auto i : adj[u]) {
        if (i == par) continue;
        parr[i] = u;
        kc[i] = kc[u] + 1;
        dfs(i,u);
        sub[u] += sub[i]; 
    }
}

vector<int>res;
void getDfs(int u, int par) {
    res.pb(u);
    // cout <<"parr " << u << ' ' << par << endl;
    for (auto i : adj[u]) {
        if (i == par) continue;
        // cout <<" dooo " << i << ' ' <<endl;
        getDfs(i,u);
    }   
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        adj[a].pb(i+1);
        adj[i+1].pb(a);
    }

    dfs(1,0);
    int mx = 0, vt = 1;
    for (int i = 1; i <= n; i++) {
        if (sub[i] >= k && kc[i] >= kc[vt]) {
            vt = i;
            mx = kc[i];
        }
    }
    // cout << vt << ' ' << mx << ' '<<parr[vt] << endl;
    getDfs(vt, parr[vt]);
    for (int i = 1; i <= k; i++) {
        cout << res[i-1] << ' ';
    }
    // EL;
    // EL;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ' ' << parr[i] << ' ' << kc[i] << ' ' << sub[i] << endl;
    // }
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