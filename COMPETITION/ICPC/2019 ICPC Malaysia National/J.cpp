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

// if u can go to v, index of u < index of v

// can use to find the longest path btw any pair of vertices

struct TopoSort {
    int n;
    bool cycle = 0;
    vector<vector<int>> adj;
    vector<bool> visit;
    vector<int> res;
    vector<bool> inStack;

    TopoSort(int n): n(n) {
        adj.resize(n + 1);
        visit.resize(n + 1);
        inStack.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int n) {
        if (visit[n]) return;
        visit[n] = 1;
        inStack[n] = 1;
        for (auto i: adj[n]) {
            if (!visit[i]) dfs(i);
            else if (inStack[i]) cycle = 1;
        }
        inStack[n] = 0;
        res.push_back(n);
    }

    void topological_sort() {
        res.clear();
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                dfs(i);
            }
        }
        reverse(res.begin(), res.end());
    }
};


int convert(char a) {
    return int(a) - int('A') + 1;
}

void solve() {
    TopoSort topo(5);
    for (int i = 1; i <= 5; i++ ) {
        string s;
        if (s[1] == '>') {
            topo.addEdge(convert(s[0]), convert(s[2]));
        }
    }    
    topo.topological_sort();
    for (auto i : topo.res) cout << i << ' ';
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}