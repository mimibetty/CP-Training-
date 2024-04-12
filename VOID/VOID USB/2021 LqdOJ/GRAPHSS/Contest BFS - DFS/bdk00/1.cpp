#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1005][1005];
bool vs[1005][1005];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool Isvalid(int x, int y) {
	if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] == '.') return 1;
	else return 0;
}

void dfs(int u, int v) {
	if (vs[u][v] == 0 && a[u][v] == '.') {
		vs[u][v] = 1;

		for (int i = 0; i <= 3; i++) {
			int x = u + dx[i];
			int y = v + dy[i];
			if (Isvalid(x,y) == 1 && a[x][y] == '.') dfs(x,y);
		}
	}
} 

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	   
 	cin >> n >> m;
 	
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			cin >> a[i][j];
 		}
 	}   

 	int res = 0;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			if (vs[i][j] == 0 && a[i][j] == '.') {
 				res++;
 				dfs(i,j);
 			}
 		}
 	}   
 	
 	cout << res;
    return 0;
}