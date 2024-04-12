#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
bool vs[100005];
int par[100005];

void dfs(int n) {
	
	vs[n] = 1;
	for (auto i : adj[n]) {
		if (vs[i] == 0) {
			vs[i] = 1;
			par[i] = n;
			dfs(i);
		}

	}
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int a,b,n,m;
 	cin >> n >> m >> a >> b;

 	for (int i = 1; i <= m; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 	}

 	for (int i = 1; i <= n; i++) {
 		sort (adj[i].begin(), adj[i].end());
 	}

 	dfs(a);

 	vector<int> trace;
 	int k = b;
 	trace.push_back(b);
 	while (k != a) {
 		k = par[k];
 		trace.push_back(k);
 	}
 	reverse(trace.begin(), trace.end());
 	
 	for (auto i : trace) cout << i << ' ';
    return 0;
}