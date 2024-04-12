#include <bits/stdc++.h>
using namespace std;

// 1-index
struct BridgeArcPoint {
    int time = 0, n;
    vector<int> num, low, criticalNodes;
    vector<vector<int>> adj;
    vector<pair<int, int>> bridges;

    BridgeArcPoint(int n, vector<vector<int>> adj): n(n), adj(adj) {
        num.resize(n + 1);
        low.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!num[i]) dfs(i, 0);
        }
    }

    void dfs(int u, int par) {
        int numChild = 0;
        low[u] = num[u] = ++time;
        bool isCriticalNode = false;
        for (auto i: adj[u]) {
            if (i == par) continue;
            if (num[i]) {
                low[u] = min(low[u], num[i]);
            }
            else {
                dfs(i, u);
                numChild++;
                low[u] = min(low[u], low[i]);
                
                if (low[i] > num[u]) {
                    bridges.push_back({u, i}); // Bridge
                }

                if (u == 1) {
                    if (numChild >= 2) isCriticalNode = true;
                }
                else {
                    if (low[i] >= num[u]) isCriticalNode = true;
                }
            }
        }
        if (isCriticalNode) criticalNodes.push_back(u); 
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj;
    adj.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BridgeArcPoint bac(n, adj);

    sort(bac.criticalNodes.begin(), bac.criticalNodes.end());
    
    cout << bac.criticalNodes.size() << "\n";
    for (auto i: bac.criticalNodes) {
        cout << i << " ";
    }

    return 0;
}