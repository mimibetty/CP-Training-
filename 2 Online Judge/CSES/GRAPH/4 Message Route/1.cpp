#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>adj[100005];
int cost[100005];
int par[100005];

void bfs(int n) {
	queue<int>q;
	q.push(n);
	while (!q.empty() ) {
		auto g = q.front();
		q.pop();

		for (auto i : adj[g]) {
			if (cost[i] == 0) {
				cost[i] = cost[g] + 1;
				par[i] = g;
				q.push(i);	
			}
		}	
	}
	
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> n >> m;
 	for (int i = 1; i <= m; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}

 	bfs(1);
 	if (cost[n] == 0) cout << "IMPOSSIBLE";
 	else {
 		vector<int>trace;
 		cout << cost[n] + 1 << endl;
 		int k = par[n];
 		trace.push_back(n);
 		for (int i = 1; i <= cost[n]; i++) {
 			trace.push_back(k);
 			k = par[k];
 		}

 		reverse(trace.begin(),trace.end() );
 		for (auto i :trace) cout<< i << ' ';
 	}
    return 0;
}