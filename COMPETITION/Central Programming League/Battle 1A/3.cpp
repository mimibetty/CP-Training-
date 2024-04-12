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

int edge[10];
int n,k,m;

struct Dijkstra {
    const long long INF = 1e18;
    typedef pair <long long, long long> II;
    vector<vector<II>> adj;
    vector<long long> d; 
    int n; 

    Dijkstra(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }
 
    void addEdge(int u, int v, long long c) {
        adj[u].push_back({v, c});
    }
    
    void dijkstra(int a) {
        priority_queue < II, vector<II>, greater<II> > pq;
 
        for (int i = 1; i <= n; i++) {
            d[i] = INF;
        }
 
        d[a] = 0;
 
        pq.push(II(0, a));
        while (!pq.empty()) {
            long long du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d[u] != du) continue;
            
            for (auto i: adj[u]){
                int v = i.first;
                long long uv = i.second;
 
                if (d[v] > du + uv){
                    d[v] = du + uv;
                    pq.push(II(d[v],v)); 
                }
            }
        }
    }
 
};

void solve2() {
    Dijkstra dijkstra1(n);
    for (int i = 1; i <= m; i++) {
        int u , v;
        long long c;
        cin >> u >> v >> c;
        dijkstra1.addEdge(u,v,c);
        dijkstra1.addEdge(v,u,c);
    }

    dijkstra1.dijkstra(edge[1]);
    cout << dijkstra1.d[edge[2]] << endl;
    return;
}

void solve3() {
    Dijkstra dijkstra1(n);
    Dijkstra dijkstra2(n);
    Dijkstra dijkstra3(n);

    for (int i = 1; i <= m; i++) {
        int u , v;
        long long c;
        cin >> u >> v >> c;
        dijkstra1.addEdge(u,v,c);
        dijkstra1.addEdge(v,u,c);

        dijkstra2.addEdge(u,v,c);
        dijkstra2.addEdge(v,u,c);

        dijkstra3.addEdge(u,v,c);
        dijkstra3.addEdge(v,u,c);
    }

    dijkstra1.dijkstra(edge[1]);
    dijkstra2.dijkstra(edge[2]);
    dijkstra3.dijkstra(edge[3]);
    
    long long res = 1e18;

    for (int i = 1; i <= n; i++) {
        long long sum = dijkstra1.d[i] + dijkstra2.d[i] + dijkstra3.d[i];
        res = min(res, sum);
    }
    cout << res << endl;
    return;
}

void solve4() {
    Dijkstra dijkstra1(n);
    Dijkstra dijkstra2(n);
    Dijkstra dijkstra3(n);
    Dijkstra dijkstra4(n);

    for (int i = 1; i <= m; i++) {
        int u , v;
        long long c;
        cin >> u >> v >> c;
        dijkstra1.addEdge(u,v,c);
        dijkstra1.addEdge(v,u,c);

        dijkstra2.addEdge(u,v,c);
        dijkstra2.addEdge(v,u,c);

        dijkstra3.addEdge(u,v,c);
        dijkstra3.addEdge(v,u,c);

        dijkstra4.addEdge(u,v,c);
        dijkstra4.addEdge(v,u,c);
    }

    dijkstra1.dijkstra(edge[1]);
    dijkstra2.dijkstra(edge[2]);
    dijkstra3.dijkstra(edge[3]);
    dijkstra4.dijkstra(edge[4]);
    
    long long res = 1e18;

    for (int i = 1; i <= n; i++) {
        long long sum = dijkstra1.d[i] + dijkstra2.d[i] + dijkstra3.d[i] + dijkstra4.d[i];
        res = min(res, sum);
    }
    cout << res << endl;
    return;
}


void solve5() {
    Dijkstra dijkstra1(n);
    Dijkstra dijkstra2(n);
    Dijkstra dijkstra3(n);
    Dijkstra dijkstra4(n);
    Dijkstra dijkstra5(n);

    for (int i = 1; i <= m; i++) {
        int u , v;
        long long c;
        cin >> u >> v >> c;
        dijkstra1.addEdge(u,v,c);
        dijkstra1.addEdge(v,u,c);

        dijkstra2.addEdge(u,v,c);
        dijkstra2.addEdge(v,u,c);

        dijkstra3.addEdge(u,v,c);
        dijkstra3.addEdge(v,u,c);

        dijkstra4.addEdge(u,v,c);
        dijkstra4.addEdge(v,u,c);

        dijkstra5.addEdge(u,v,c);
        dijkstra5.addEdge(v,u,c);
    }

    dijkstra1.dijkstra(edge[1]);
    dijkstra2.dijkstra(edge[2]);
    dijkstra3.dijkstra(edge[3]);
    dijkstra4.dijkstra(edge[4]);
    dijkstra5.dijkstra(edge[5]);
    
    long long res = 1e18;

    for (int i = 1; i <= n; i++) {
        long long sum = dijkstra1.d[i] + dijkstra2.d[i] + dijkstra3.d[i] + dijkstra4.d[i] + dijkstra5.d[i];
        res = min(res, sum);
    }
    cout << res << endl;
    return;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> k >> m;

    for (int i = 1; i <= k; i++) {
        cin >> edge[i];
    }

    // for (int i = 1; i <= k ;i++) cout << edge[i] << endl;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (k == 2) {
        solve2();
        return 0;    
    }

    if (k == 3) {
        solve3();
        return 0;    
    }
    
    if (k == 4) {
        solve4();
        return 0;    
    }
    if (k == 5) {
        solve5();
        return 0;    
    }

    return 0;
}