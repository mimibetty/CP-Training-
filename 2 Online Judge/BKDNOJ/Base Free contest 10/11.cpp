#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 

 
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

int cost[12][12];
bool vs[12][12];
pair<int,int> par[12][12];
 
bool is_valid(int x,int y) {
    if (x > 0 && x <= 8 && y > 0 && y <= 8) return 1;
    else return 0;
}
 
 
void bfs(int x, int y) {
 
    queue<pair<int,int>> q;
    q.push({x,y});
    vs[x][y] = 1;
 
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
        	for (int j = 1; j <= 8; j++) {
	            int newX = u.first + dx[i]*j;
	            int newY = u.second + dy[i]*j;
	            if (is_valid(newX,newY) == 1) {
	            	if (vs[newX][newY] == 0) {
		                cost[newX][newY] = cost[u.first][u.second] + 1;                
		                vs[newX][newY] = 1;
		                q.push({newX,newY});
		                par[newX][newY] = {u.first,u.second};
		           //     bfs(newX,newY);
	            	}	
	            } 
        	}
        }
    }
}
void solve() {
	char ad1,ad2;
	int xa,ya, xb,yb;
	cin >> ad1 >> ya >> ad2 >> yb;
	xa = ad1 - 64;
	xb = ad2 - 64;

	if (xa == xb && ya == yb) {
		cout << 0 << ' ' << ad1 << ' ' << ya << endl;
		return;
	}

	bfs(xa,ya);
	if (cost[xb][yb] == 0) {
		cout << "Impossible" << endl;
		
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				cost[i][j] = 0;
				vs[i][j] = 0;
			}
		}
		return;
	}
	else {
		cout << cost[xb][yb] << ' ';
		vector<pair<int,int>>trace;
		int x = xb, y = yb;
		trace.pb({x,y});
        while (x != xa || y != ya) {
        //  cout << x << ' ' << y << endl;
            auto p = par[x][y];
       //     cout << p.first << ' ' << p.second <<endl;
            x = p.first;
            y = p.second;
           trace.pb({x,y});
        }

       
        reverse(trace.begin(), trace.end() );
        for (auto i : trace) cout << (char)(i.fi + 64) << ' ' << i.se << ' '; 
        cout << endl;

        for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				cost[i][j] = 0;
				vs[i][j] = 0;
			}
		}

		return;
	}
} 
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
    return 0;
}