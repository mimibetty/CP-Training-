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
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int n,m;
int x,y,u,v;
char a[1005][1005];
int d[1005][1005];

bool isvalid(int x,int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
	return 0;
}

void bfs(int gx, int gy) {
	deque<pair<int,int>>deq;
	deq.push_back({gx,gy});
	d[gx][gy] = 0;
 	
 	while (deq.empty() == 0) {
 		auto p = deq.front();
 		deq.pop_front();

 		for (int i = 0; i < 4; i++) {
 			int xx = p.fi + dx[i];
 			int yy = p.se + dy[i];

 			if (isvalid(xx,yy) == 0) continue;

 			int wei = 0;
 			if (a[xx][yy] == '*') wei = 1;
 			if (d[xx][yy] == -1 || d[xx][yy] > d[p.fi][p.se] + wei) {
 				d[xx][yy] = d[p.fi][p.se] + wei;
	 			if (wei) deq.push_back({xx,yy});
	 			else deq.push_front({xx,yy});
 			}
 		}
 	}
 	return;
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
 			cin >> a[i][j];
 			d[i][j] = -1;
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