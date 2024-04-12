#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
int par[100005];
int d[100005];

void bfs(int n) {
	queue<int>q;
	q.push(n);
	while (!q.empty() ) {
		auto g = q.front();
		q.pop();

		for (auto i : adj[g]) {
			if (d[i] == 0) {
				d[i] = d[g] + 1;
				par[i] = g;
				q.push(i);	
			}
		}	
	}
	
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,m,l,r;
 	cin >> n >> m >> l >> r;

 	for (int i = 1; i <= m; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 	}   

 	for (int i = 1; i <= n; i++) {
 		sort(adj[i].begin(), adj[i].end());
 	}   

 	bfs(l);
 	cout << d[r] << endl;

 	int k = r;
 	vector<int>trace;

 	while (k != l) {
 		trace.push_back(k);
 		k = par[k];
 	}
 	trace.push_back(l);
 	reverse(trace.begin(),trace.end());
   	for (auto i :trace) cout<< i << ' ';
    return 0;
}