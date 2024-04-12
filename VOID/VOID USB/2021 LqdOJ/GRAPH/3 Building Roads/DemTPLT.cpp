#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>a[1000005];
bool vs[100005];

void dfs(int n) {
	vs[n] = 1;
   
	for (auto i : a[n]) {
		if (vs[i] == 0) {
			vs[i] == 1;
			dfs(i);
		}
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
    	int u,v;
    	cin >> u >> v;
    	a[u].push_back(v);
    	a[v].push_back(u);
    }

    long long res = 0;
    for (int i = 1; i <= m; i++) {
    	if (vs[i] == 0) {
    		dfs(i);
    		res++;
    	}
    }
    cout << res;
    return 0;
}