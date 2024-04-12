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
    int minval,maxval;
};

long long root[300005];
inf tt[300005];

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
    tt[a].minval = min(tt[a].minval, tt[b].minval);
    tt[a].maxval = max(tt[a].maxval, tt[b].maxval);

    root[a] += root[b];
    root[b] = a;
}

void get(int a) {
    a = findRoot(a);
    cout << tt[a].minval << ' ' << tt[a].maxval << ' ' << abs(root[a]) << endl;

    return;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,t;
    cin >> n >> t ;
    for (int i = 0; i <= n; i++) {
        root[i] = -1;
        tt[i].minval = tt[i].maxval = i; 
    } 

    while (t--) {
        int u,v;
        string s;
        cin >> s;

        if (s == "union") {
            cin >> u >> v;
            merge(u,v);
        }
        else {
            cin >> u;
            get(u);
        }
    }
    return 0;
}