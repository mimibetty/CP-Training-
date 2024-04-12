#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,m;
 	vector<int> ans;
 	cin >> n >> m;

 	for (int i = 1; i <= m; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
 	}

 	int res = 0;
 	for (int i = 1; i <= n; i++) {
 		if (adj[i].size() > 1) {
 			for ()
 			res++;
 			ans.push_back(i);
 		}
 	}

 	sort(ans.begin(), ans.end());
 	cout << res << endl;
 	for (auto i : ans) cout << i << ' ';
    return 0;
}