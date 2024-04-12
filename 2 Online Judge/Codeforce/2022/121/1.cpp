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

char a[55][55];

void solve() {
	int n,m,x,y;
	cin >> n >> m  >> x >> y;

	bool done = 0, ok = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B') {
				done = 1;
			}
			if (i == x && a[i][j] == 'B') ok = 1;
			if (j == y && a[i][j] == 'B') ok = 1;
				
		}
	}

	if (a[x][y] == 'B') {
		cout << 0 << endl;
		return;
	}
	if (done == 0) cout << -1 <<endl;
	else {
		if (ok == 0) cout << 2 <<endl;
		else cout << 1 <<endl;
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