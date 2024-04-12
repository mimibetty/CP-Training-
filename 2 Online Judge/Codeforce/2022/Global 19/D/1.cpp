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
 
long long a[105];
long long b[105];
long long dp[105][10005];

void solve() {
	int n;
	cin >> n;

	long long res = 1e18;
	long long sum = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		sum += b[i];
	}
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j - a[i] >= 0) dp[i][j] = dp[i][j] | dp[i-1][j - a[i]];
			if (j - b[i] >= 0) dp[i][j] = dp[i][j] | dp[i-1][j - b[i]];
		}
	}

// for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j <= 10000; j++) {
// 			if (dp[i][j]) cout << i << ' ' << j << endl;
// 		}
// 	}
	for (int i = 0; i <= 10000; i++) {
		if (dp[n][i] == 1) {
			long long val = 1ll * (1ll * (sum - i) * (sum - i) +  1ll * i * i);
			res = min(res, val);
		}
	}

	for (int i = 1; i <= n; i++) {
		res += 1ll * a[i] * a[i] *(n-2);
		res += 1ll * b[i] * b[i] *(n-2);
	
	}

	cout << res << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) dp[i][j] = 0;
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	for (int z = 1; z <= t; z++) {
 		solve();
 	}
    return 0;
}
