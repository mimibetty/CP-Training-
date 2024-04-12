#include<bits/stdc++.h>
using namespace std;
 
char a[1005][1005];
int m,n;
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vs[1005][1005];
 
 
bool isvalid(int u, int v) {
	if ( u >= 1 && u <= n && v >= 1 && v <= m) return 1;
	return 0;
}
 
 
void dfs(int  u, int v) {
	if (vs[u][v] == 0 && a[u][v] == '.') {
		vs[u][v] = 1;
		//cout << u << ' ' << v << endl;
		for (int i = 0; i <= 3; i++) {
			int newU = u + dx[i];
			int newV = v + dy[i];
			if (isvalid(newU, newV) == 1 && a[newU][newV] == '.') dfs(newU, newV);			
		}
	}
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    	}
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (a[i][j] == '.' && vs[i][j] == 0) {
    			dfs(i, j);
    			cnt++;	
    		}
    	}
    }
    cout << cnt;
    return 0;
}