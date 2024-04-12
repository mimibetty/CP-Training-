#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>adj[100005];
int color[100005];

void dfs(int n) {
	for (auto i : adj[n]) {
		if( color[i] == 0 ) {
			color[i] = 3 - color[n];
			dfs(i);
		}
	}
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= m ; i++) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
    	if (color[i] == 0) {
    		color[i] = 1;
    		dfs(i);	
    	}
    }
    

    bool check = 1 ;
    for (int i = 1; i <= n; i++) {
    	for (auto j : adj[i]) {
    		if (color[j] == color[i]) {
    			check = 0;
    			break;
    		}
    		if (check == 0) break;
    	}
    }

    if (check == 1) {
    	for (int i = 1; i <= n; i++) {
    		cout << color[i] << ' ';
    	}
    }
    else {
    	cout <<"IMPOSSIBLE";		
    }
    return 0;
}