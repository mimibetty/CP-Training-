#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vs[100005];

void dfs(int n) {
		vs[n] == 1;
		for (auto i :adj[n]) {
			if (vs[i] == 0) {
				vs[i] = 1;
				dfs(i);
			}
		}
	
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
 	int n,m;
 	cin >> n >> m ;

 	for (int i = 1; i <= m; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}

 	int res = 0;

 	for (int i = 1; i <= n; i++) {
 		if (vs[i] == 0) {
 			res++;
 			dfs(i);
 		}
 	}
 	cout << res - 1; 
    return 0;
}