#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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

char a[1005][1005];
int d[1005][1005];
int n,m;
int x,y,u,v;

bool isvalid (int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
	return 0;
}

void bfs(int gx, int gy) {
	deque<pair<int,int>>dq;
	dq.push_back({gx,gy});
	d[gx][gy] = 0;

	while (dq.empty() == 0) {
		auto u = dq.front();
		dq.pop_front();

		for (int i = 0 ; i < 4; i++) {
			int xx = u.fi + dx[i];
			int yy = u.se + dy[i];
			if (isvalid(xx,yy) == 0) continue;
			int w = 0;
			if (a[xx][yy] == '*') w = 1;


			if (d[xx][yy] == -1 || d[xx][yy] > d[u.fi][u.se] + w) {
				d[xx][yy] = d[u.fi][u.se] + w;	
				if (a[xx][yy] == '*') dq.push_back({xx,yy});
				else dq.push_front({xx,yy});
			} 
		}

	}
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> n >> m;

 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			d[i][j] = -1;

 			cin >> a[i][j];
 			if (a[i][j] == 'G') {
 				x = i;
 				y = j;
 			}
 			if (a[i][j] == 'R') {
 				u = i;
 				v = j;
 			}
 		}
 	}

 	bfs(x,y);
 	cout << d[u][v] << endl;
    return 0;
}