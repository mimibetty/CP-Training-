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

int a[200005];
long long ps[200005];

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i-1] + a[i];	
	} 
	long long ans = 1e9;
	for (int i = 1; i <= n; i++) {
		long long lim = (ps[1] -ps[i])/(n - i + 1);
		// if (lim >= a[1]) {
		// 	cout << 0 << endl;
		// 	return;
		// }
		long long x = a[1] - lim;
		long long tong = ps[i] - ps[1] + (n-i+1)*(a[1] - x); 
		x += (n-i);
		ans = min(ans, x);
		// cout << i << ' ' <<lim  << ' ' <<  x<<' '<<tong << endl;
		cout << i << ' ' << lim << endl;
	}
	cout << ans << endl;

	// int lower = 0, uper = 1e9;
	// while (lower < uper) {
	// 	int mid = (lower + uper )/2;
	// 	if (check(a,mid) == 1) uper = mid;
	// 	else lower = mid + 1;
	// }
	// cout << lower << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		// cout << t <<endl;
 		// cout << endl;
 		solve();
 	}
    return 0;
}