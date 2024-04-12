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
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
int n,m;
char a[1005][1005];
char b[1005][1005];
int cost[1005][1005];
bool vs[1005][1005];

bool check(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
	return 0 ;
}

// void bfs(vector<pii>&q) {
// 	auto p = q.front;
// 	vs[p.fi][p.se] 
// }

// bool solve(int mid) {
// 	queue<pii>q;

// 	for (auto i : )
// }

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> n >> m;
 	vector<pair<int,int>>pos;
 	queue<pii>q;

 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			cin >> a[i][j];
 			if (a[i][j] == 'L') pos.pb({i,j});
 			if (a[i][j] == '.' || a[i][j] == 'L') if (a[x][y] == '.') vt.push({i,j});
 		} 
 	}

	while (q.size()) {
		auto p = q.front();
		q.pop();
		// vs[p.fi][p.se] = 1;

		for (int i = 0; i < 4; i++) {
			int u = p.fi + dx[i];
			int v = p.se + dy[i];
			if (check(u,v)) {
				if (cost[u][v] == 0 && a[u][v] == 'X') {
					q.push({u,v});
					cost[u][v] = cost[p.fi][p.se] + 1;
				}
			}
		}

	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << cost[i][j] << ' ';
		cout << endl;
	}
	
 	// int lower = 0; uper = 1e9; 
 	// int mid;

 	// while (lower < uper) {
 	// 	mid = (lower + uper) /2;
 	// 	if (solve(mid)) uper = mid;
 	// 	else lower = mid + 1;
 	// }

 	// cout << lower;
    return 0;
}