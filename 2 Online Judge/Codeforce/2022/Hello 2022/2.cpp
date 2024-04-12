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
 
void solve() {
	int n;
	cin >> n;
	long long l,r,cost;
	long long sum = 0;
	long long l1 = 1e18,r1 = 0,cost1 = 1e18,l2 = 1e18,r2 = 0,cost2 =1e18;
	long long lx = 0,rx = 0, costx = 1e18;
	for (int i = 1; i <= n; i++) {
		long long l,r,cost;
		cin >> l >> r >> cost;
		if (rx - lx <= r - l) {
			if (rx - lx == r - l) {
				costx = min(costx,cost);
			}
			else {
				lx = l;
				rx = r;
				costx = cost;	
			}
		}

		if (l <= l1) {
			if (l == l1) {
				cost1 = min(cost,cost1);
			}
			else {
				l1 = l;
				r1 = r;
				cost1 = cost;
			}
		}
		if (r >= r2) {
			if (r == r2) {
				cost2 = min(cost,cost2);
			}
			else {
				l2 = l;
				r2 = r;
				cost2 = cost;
			}
		}

		if (r2 - l1 >= rx - lx) {
			if (r2 - l1 == rx - lx) cout << min(costx,cost2+cost1) << endl;
			else {
				cout << cost2 + cost1 << endl;
			}
		}
		// cout << l1 << ' ' << r1 << ' '<< cost1 << endl;

		// cout << l2 << ' ' << r2 << ' '<< cost2 << endl;

		// cout << lx << ' ' << rx << ' '<< costx << endl;
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