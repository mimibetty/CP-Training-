#include<bits/stdc++.h>
using namespace std;
 
 struct Dijkstra {
    const long long INF = 1e18;
    typedef pair <long long, long long> II;
    vector<vector<II>> adj;
    vector<long long> d; // shortest dist
    int n; // number of vertices

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

                // this v is better
                if (d[v] > du + uv){
                    d[v] = du + uv;
                    pq.push(II(d[v],v)); // push the better one
                }
            }
        }
    }

};

 
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
 
 
    Dijkstra dijkstra1(n);
    Dijkstra dijkstraN(n);
    for (int i = 1; i <= m; i++) {
        int u , v ,c;
        cin >> u >> v >> c;
        dijkstra1.addEdge(u,v,c);
        dijkstraN.addEdge(v,u,c);
    }
    dijkstra1.dijkstra(1);
    dijkstraN.dijkstra(n);
 
    long long res = 1e18;
    for (int i = 1; i <= n; i++) {
        for (auto j : dijkstra1.adj[i]) {
            res = min(res, dijkstra1.d[i] + dijkstraN.d[j.first] + j.second/2 );
        }
    }
    cout << res;
    return 0;
}