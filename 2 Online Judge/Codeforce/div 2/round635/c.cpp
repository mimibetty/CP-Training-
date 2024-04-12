#include<bits/stdc++.h>
using namespace std;
long long a[100005];

vector<int> adj[100005];
bool visited[100005];

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        dfs(adj[u][i]);
    }
}
int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n,k;
        cin >> n >> k;
        for (int i = 1; i < n; i++) {
            int x,y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        long long res = 0;
        for (int i = )
        return 0;
    }

