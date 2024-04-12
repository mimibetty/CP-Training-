#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1005][1005];
int d[1005][1005];
pair<int,int>par[1005][1005];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool Isvalid( int x,int y) {
	if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] != '#') return 1;
	else return 0;
}

void bfs(int u, int v) {
	queue <pair<int,int>> q;
	q.push({u,v});

	while ( q.empty() == 0) {
		auto g = q.front();
		q.pop();

		int x,y;
		for (int i = 0; i <= 3; i++) {
			x = g.first + dx[i];
			y = g.second + dy[i];
			
			if (Isvalid(x,y) == 1 && d[x][y] == 0) {
				d[x][y] = d[g.first][g.second] + 1;
				par[x][y] = {g.first,g.second};
				q.push({x,y});
			} 
		}
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    cin >> n >> m;

    int xa,xb,ya,yb;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    		if (a[i][j] == 'A') {
    			xa = i;
    			ya = j;
    		} 
    		if (a[i][j] == 'B') {
    			xb = i;
    			yb = j;
    		} 
    	}
    }

    bfs(xa,ya);
    if (d[xb][yb] == 0) cout << "NO";
    else {
    	cout << "YES" << endl;
    	/*cout << d[xb][yb] << endl;

    	int l = xb, r = yb;
    	vector<char>trace;

    	while (l != xa || r != ya) {
    		auto g = par[l][r];
    		int xx = g.first;
    		int yy = g.second;
    		if (l == xx + 1 ) trace.push_back('D');
    		if (l == xx - 1 ) trace.push_back('U');
    		if (r == yy + 1 ) trace.push_back('R');
    		if (r == yy - 1 ) trace.push_back('L');
    		l = xx;
    		r = yy;
    	}
    	reverse(trace.begin(), trace.end());
    	for (auto i : trace) cout << i <<' ';*/
    }
    return 0;
}