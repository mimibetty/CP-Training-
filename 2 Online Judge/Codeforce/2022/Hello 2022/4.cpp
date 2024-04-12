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
 
long long a[505][505];
void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= 2*n; i++) {
		for (int j = 1; j <= 2*n; j++) {
			cin >> a[i][j];
		}
	}
	long long sum = 0;

	for (int i = n + 1; i <= 2*n; i++) {
		for (int j = n+1; j <= 2*n; j++) sum+=a[i][j];
	}

	long long min1 = min({a[1][n + 1], a[1][2 * n], a[n][n + 1], a[n][2 * n]});
    min1 = min({min1, a[n  + 1][1], a[n + 1][n], a[2 * n][1], a[2 * n][n]});
	cout << sum + min1 << endl; 
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