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

int a[1005];
int root[1005];
vector<int>adj[1005];

int findRoot(int u) {
    while (root[u] >= 0) {
        u = root[u];
    }
    return u;
}

void merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    
    if (a == b) return;

    if (root[a] > root[b]) {
        swap(a, b);
    }

    root[a] += root[b];
    root[b] = a;

    adj[a].pb(b);
    for (auto i :  adj[b]) {
        adj[a].pb(i);
    }

    adj[b].clear();
    return;
}

unsigned long long lcmm(unsigned long long a,unsigned long long b) {
    return (a/__gcd(a,b)) * b;
}

void solve() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    s = ' ' + s;

    for (int i =1; i <= n; i++) {
        cin >> a[i];
        root[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        merge(i, a[i]);
    }

    vector<int>dd;
    for (int i = 1; i <= n; i++) {
        if (root[i] < 0) dd.pb(i);
    }

    bool ok = 1;

    for (auto i : dd) {
        // cout << i << endl;
        if (adj[i].size() == 1) continue;
        // cout << "Stt  " << i << endl;
        for (int j = 0; j < adj[i].size() - 1; j++) {
            if (s[adj[i][j] ] !=  s[adj[i][j+1] ]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) break;
    }
    

    if (ok) {
        cout << ok << endl;
        return;
    }

    unsigned long long res = abs(root[dd[0]]);
    for (auto i : dd) {
        unsigned long long q = abs(root[i]);
        res = lcmm(res, q);
    } 

    cout << res << endl;

    for (int i = 0; i <= n; i++) adj[i].clear();
        return;

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
    // cout << lcmm(2,3) << endl;
    for  (int zz = 1; zz <= t; zz++) {
        // cout <<"STT   " <<zz << endl; 
        solve();
    }
    return 0;
}