#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100005];
int cost[100005];
bool visit[100005];

void bfs(int n) {
    queue <int> q;
    q.push(n);
    visit[n] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            if (visit[i] == false) {
                visit[i] = true;
                cost[i] = cost[u] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int n, m, x, u , v, p;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);
    if ( cost[n] == 0) cout << "IMPOSSIBLE";
    else cout << cost[n] + 1;
    return 0;
}

