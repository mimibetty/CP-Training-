#include <bits/stdc++.h>

using namespace std;

// 0 is false, 1 is true
vector <int> adj[100005];
bool vs[100005];

void dfs(int n) {
    vs[n] = 1;
    
    for (auto i: adj[n]) {
        if (vs[i] == 0) {
            vs[i] = 1;
            dfs(i);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
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

    long long res = 0;
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (vs[i] == 0) {
            res++;
            vs[i] = 1;
            dfs(i);
            ans.push_back(i);
        }
    }
    
    cout << res - 1 << endl;
    int k = res - 1;
    for (int i = 0; i < k; i++) {
        cout << ans[i] <<' '<< ans[i+1] << endl;
    }
    return 0;
}
