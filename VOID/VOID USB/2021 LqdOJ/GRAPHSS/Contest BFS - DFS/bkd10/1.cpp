#include <bits/stdc++.h>

using namespace std;

// 0 is false, 1 is true
vector <long long> adj[100005];
bool visit[100005];

void dfs(int n) {
    if (visit[n]) return;
    visit[n] = 1;
    for (auto i: adj[n]) {
        dfs(i);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int x;
    cin >> x;

    int res = 0;
    dfs(x);
    
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) res++;
    }
    cout << res;
    return 0;
}
