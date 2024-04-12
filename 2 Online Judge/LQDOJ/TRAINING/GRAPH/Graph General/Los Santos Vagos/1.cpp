#include <bits/stdc++.h>
using namespace std;

// 0 is false, 1 is true
vector <int> adj[100005];
vector <int>ans[100005];
bool visit[100005];

void dfs(int n,int res) {
    ans[res].push_back(n);
    visit[n] = 1;
    for (auto i: adj[n]) {
        if ( visit[i] == 0) {
        	dfs(i,res);	
        }
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
    }

   	for (int i = 1; i <= m; i++) {
     	sort(adj[i].begin(), adj[i].end());
    }

    int res = 0;
  	for (int i = 1; i <= n; i++) {
  		if (visit[i] == 0) {
  			res++;
  			dfs(i,res);
  			vector<int>ans;

  		}
  	}
  	cout << res << endl;
  	for (int i = i; i <= res; i++) {
  		for (auto j : ans[i]) cout << j << ' ';
  	}
    return 0;
}
