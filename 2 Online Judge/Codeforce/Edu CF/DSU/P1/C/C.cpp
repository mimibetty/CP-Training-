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


long long root[200005];
vector<int>adj[200005];
long long add[200005];
long long res[200005];


int findRoot(int u) {
    while (root[u] >= 0) {
        u = root[u];
    }
    return u;
}

void bfs(int u, int oldroot, int newroot) {
    if (adj[u].size() > 0) {
        for (auto i : adj[u]) {
            res[u] = res[u] + add[oldroot] - add[newroot];
            if (adj[i].size() > 0) bfs(i, oldroot, newroot);
        }
    }
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
    bfs(b, b , a);
    res[b] = res[b] + add[b] - add[a];
    add[b] = 0;

    return;
}

void get(int a) {
    long long par = findRoot(a);

    cout << add[par] + res[a] << endl;
    return;
}

void FUNCADD(int u, int point) {
    u = findRoot(u);
    add[u] += point;
    return; 
}


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,t;
    cin >> n >> t ;
    for (int i = 0; i <= n; i++) {
        root[i] = -1;
    } 

    for (int z = 1; z <= t; z++) {

        int u,v;
        string s;
        cin >> s;

        if (s == "join") {
            cin >> u >> v;
            merge(u,v);
        }
        if (s == "add") {
            cin >> u >> v;
            FUNCADD(u,v);
        } 
        if (s == "get") {

            cin >> u;
            cout << z << ' ';
            get(u);
        }
    }
    return 0;
}