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

// int nn;
// int cycle;
bool vs[200005];
vector<int>adj[200005];
int par[200005];
bool check;
bool okk;
vector<int> trace;

// void dfs(int u) {
//     nn++;
//     vs[u] = 1;        
//     for (auto i : adj[u]) {
//         if (vs[i] == 1) cycle = 1;
//         if (vs[i] == 0) {
//             dfs(i);
//         }
//     }
// }



void dfs(int n) { 
    vs[n] = 1;
    if(trace.size()) return;
    for (auto i :adj[n]) {
        // cout << i << endl;
        if (vs[i] == 0) {
            par[i] = n;
            vs[i] = 1;
            dfs(i);
        }
        else if (vs[i] == 1 && par[n] != i) {           
             
            check = 1;
 
            int k = i;
            int x = n;
            trace.push_back(i);
            while ( x != k && x > 0) {
                trace.push_back(x);
                x = par[x]; 
            }
            trace.push_back(i);
            // reverse(trace.begin(), trace.end());
 
            // cout <<"SSIII" <<  trace.size() << endl;
            if (trace.size() % 2 == 0) okk = 1;
            // cout << endl;
            // for (auto s :trace) cout << s <<' ';
            // exit(0);
            return;
            // continue;
            // cout << 100 << endl;
        }
        else if (vs[i] == 1) break;
    }

    return;
}


void solve() {
    int n;
    cin >> n;
    // cout << n << endl;
    check = 0;
    okk = 0;
    for (int i = 1; i <= n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool yup = 0;
    for (int i = 1; i <= n; i++) {
        // if (ok) break;
        if(vs[i] == 1) continue;
        // cycle = 0; 
        // nn = 0;
        // cout << i << endl;
        if (check == 0 || okk == 0) {
            cout << "STT  " << i ;
            dfs(i);
            cout << endl;
            if (check == 1 && okk == 1) {
                // cout << "STT   " << i ;
                yup = 1;  
            } 
        } 
        else break;
        check = 0;
        okk = 0;
        trace.clear();
        // cout << i << ' ' << nn << endl;
        // if (cycle == 1 && nn % 2 == 1) ok = 1;
    }

    if (yup == 0) cout << "yes" << endl;
    else cout << "no" << endl;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        par[i] = 0;
        vs[i] = 0;
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