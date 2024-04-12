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

int a[105][105];
int n,m;
bool check(int x, int y ) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
	return 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	
	bool ok = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0) continue;
			if (i != 2 && j != 3) continue;
			int x1 = i - 1, y1 = j;
			int x2 = i, y2 = j - 1;
			int x3 = i + 1, y3 = j;
			int x4 = i, y4 = j + 1;
			if (check(x1,y1) == 1 && check(x2,y2) == 1 && check(i-1,j-1) == 1) {
				if (a[x1][y1] == 1 && a[x2][y2] == 1 && a[i-1][j-1] == 0) {
					cout << "YES" << endl;
				}	
				c			
			}
			if (check(x2,y2) == 1 && check(x3,y3) == 1 && check(i+1,j-1) == 1) {
				if (a[x2][y2] == 1 && a[x3][y3] == 1 && a[i+1][j-1] == 0) {
					cout << "YES" << endl;
				}				
			}
			if (check(x3,y3) == 1 && check(x4,y4) == 1 && check(i+1,j+1) == 1) {
				if (a[x3][y3] == 1 && a[x4][y4] == 1 && a[i+1][j+1] == 0) {
					cout << "YES" << endl;
				}				
			}
			if (check(x1,y1) == 1 && check(x4,y4) == 1 && check(i-1,j+1) == 1) {
				if (a[x1][y1] == 1 && a[x4][y4] == 1 && a[i-1][j+1] == 0) {
					cout << "YES" << endl;
				}				
			}
		}
	}

	cout << "NO" << endl;	
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while(t--) {
 		solve();
 	}

    return 0;
}