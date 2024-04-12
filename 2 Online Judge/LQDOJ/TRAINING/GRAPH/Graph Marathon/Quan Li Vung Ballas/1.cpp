#include<bits/stdc++.h>
using namespace std;

bool vs[100005];
int par[100005];
vector<int> adj[100005],trace[100005];

void dfs(int n,int m) {
	vs[n] = 1;
	trace[m].push_back(n);

	for (auto i : adj[n]) {
		if (vs[i] == 0) {
			vs[i] = 1;
			par[i] = n;		
			dfs(i,m);	
		}
	}

}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,m;
 	cin >> n >> m;

 	for (int i = 1; i <= m; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}   

 	for (int i = 1; i <= n; i++) {
 		sort(adj[i].begin(), adj[i].end());
 	}

	int res = 0; 	
 	for (int i = 1; i <= n; i++) {
 		if (vs[i] == 0) {
 			res++;
 			dfs(i,res);
 		}
 	}

 	cout << res << endl;
    
	for (int i = 1; i <= res; i++) {
 		sort(trace[i].begin(), trace[i].end());
 		cout << trace[i].size() << ' ';
 		for (auto j : trace[i]) cout << j << ' ';
 		cout << endl;
 	}   


    return 0;
}