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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const int dx8[8] = {1,1,1,0,0,-1,-1,-1}, dy8[8] = {-1,0,1,-1,1,-1,0,1};

const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
int n,m;
bool vs[1005][1005];
char a[1005][1005];
int cost[1005][1005];

bool check(int u, int v) {
	if (u >= 1 && u <= n && v >= 1 && v <= m && a[u][v] != '*') return 1;
	return 0;
}

void bfs(int u, int v) {
	queue<pair<int,int>>q;
	q.push({u,v}); 
	vs[u][v] = 1;
	
	while (q.size()) {
		auto p = q.front();
		q.pop();
		vs[p.fi][p.se] = 1;

		for (int i = 0; i < 4; i++) {
			int x = p.fi + dx[i];
			int y = p.se + dy[i];
			if (check(x,y) == 1) {
				if (vs[x][y] == 0) {
					cost[x][y] = cost[p.fi][p.se] + 1;
					vs[x][y] = 1;

					q.push({x,y});				
				} 
			} 
		}

	}
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> n >> m;
 	int xb,yb,xc,yc;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m ;j++) {
 			cin >> a[i][j];
 			if (a[i][j] == 'B') {
 				xb = i;
 				yb = j;
 			}	 		
 			if (a[i][j] == 'C') {
 				xc = i;
 				yc = j;
 			}	 			
 		} 	
 	} 
 	
 	bfs(xb,yb);
 	cout << cost[xc][yc];
    return 0; 
}