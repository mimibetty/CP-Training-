#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1005][1005];
bool vs[1005][1005];
pair<int,int> par[1005][1005];
int dm[1005][1005], da[1005][1005];

bool IsValid(int x, int y) {
	if ( x > 0 && x <= n && y > 0 && y <= m && a[x][y] == '.' ) return 1;
	else return 0;
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;

    queue<pair<int,int>> monster,aa;
    vector<pair<int,int>>target;
    vector<char>trace;
    bool check = 0;
    int xa,ya;
    int xd,yd;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];

    		if (a[i][j] == 'A') {
    			xa = i;
    			ya = j;
    			aa.push({i,j});
    		}
    		else if (a[i][j] == 'M') {
    			monster.push({i,j});
    		}
    		else if ( (i == 1 || i == n || j == 1 || j == m) && a[i][j] == '.') {
    			target.push_back({i,j});
    		}
    	}
    }

    //bfs A
    //da[g.first][g.second]++;
    if (xa == 1 || xa == n || ya == 1 || ya == m) cout << "YES" << endl << 0;
    else {
    	while ( !aa.empty() ) {
	    	auto g = aa.front();
	    	aa.pop();
	    	int x,y;
	    	for (int i = 0; i <= 3; i++) {
	    		x = g.first  + dx[i];
	    		y = g.second + dy[i];
	    		if (da[x][y] == 0 && IsValid(x,y) == 1) {
		    		aa.push({x,y});
		    		da[x][y] = da[g.first][g.second] + 1;
		    		par[x][y] = {g.first,g.second};
		    	}
	    	}
	    }
	    //bfs monster 
		while ( !monster.empty() ) {
	    	auto g = monster.front();
	    	vs[g.first][g.second] = 1;
	    	monster.pop();
	    	int x,y;
	    	for (int i = 0; i <= 3; i++) {
	    		x = g.first  + dx[i];
	    		y = g.second + dy[i];
	    		if (dm[x][y] == 0 && IsValid(x,y) == 1) {
		    		monster.push({x,y});
		    		dm[x][y] = dm[g.first][g.second] + 1;
		    		vs[x][y] =  1;
		    	}
	    	}
	    }    
	    
	    for (auto i : target) {
	    	if ( (da[i.first][i.second] > 0 && vs[i.first][i.second] == 0) || (da[i.first][i.second] < dm[i.first][i.second] && da[i.first][i.second] > 0))  {
	    		cout << "YES" << endl;
	    		cout << da[i.first][i.second] <<endl;
	    		check = 1;
	    		xd = i.first;
	    		yd = i.second;
	    		break;	
	    	}
	    }
	    /* for (auto i : target) {
	    		cout << da[i.first][i.second] <<endl;
	    		cout << dm[i.first][i.second] <<endl << '.';
	    			
	    }*/
	    if (check == 0) cout << "NO";
	    else {
	    	int x = xd, y = yd;
	    	int xx , yy;
	    	while (x != xa || y != ya) {
 		//	cout << x << ' ' << y << endl;
 			xx = x, yy = y;
 			auto p = par[xx][yy];
 			x = p.first;
 			y = p.second;
 			if (xx == x - 1) trace.push_back('U');
 			if (xx == x + 1) trace.push_back('D');
 			if (yy == y - 1) trace.push_back('L');
 			if (yy == y + 1) trace.push_back('R');
 			}
 			if (xa == x - 1) trace.push_back('U');
 			if (xa == x + 1) trace.push_back('D');
 			if (ya == y - 1) trace.push_back('L');
 			if (ya == y + 1) trace.push_back('R');
 		//	cout << xa << ' ' << ya << endl;
 			reverse(trace.begin(), trace.end() );
 			for (auto i : trace) cout << i;
 		}
	}

    return 0;
}