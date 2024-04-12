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
 
 
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long l;
 	int n;
 	cin >> l >> n;

 	vector<pair<double, int>>a;

 	for (int i = 1; i <= n ; i++) {
 		double vt,d;
 		cin >> vt >> d;

 		a.pb({vt,d});
 	} 
 	double res = 0;

 	while (1) {
 		double minval = 1e18;
 		for (int i = 0; i < n - 1; i++) {
 			if (a[i].se == 1 && a[i+1].se == 0) {
 				minval = min(minval, abs(a[i].fi - a[i+1].fi));
 			}
 		}
 		if (minval == 1e18) {
 			cout << res << endl;
 			return 0;
 		}

 		for (int i = 0; i < n; i++) {
 			if (a[i].fi <= 0 || a[i].fi >= l) continue;
 			// if (i != (n - 1)) {

 			// }
  			if (a[i].se == 1 && a[i+1].se == 0) {
 				if (abs(a[i].fi - a[i+1].fi) == minval) {
					a[i].fi += minval/2;
					a[i+1].fi -= minval/2;
 					a[i].se = 0;
 					a[i+1].se = 1;
 					i++;
 				}
 				else {
 					a[i].fi += minval/2;
					a[i+1].fi -= minval/2;
 				}
 			}
 			else {
	 			if (a[i].se == 0) {
	 				a[i].fi -= (minval/2);
	 			}
	 			else a[i].fi += (minval/2);
 			}
 		} 
 		res += minval/2;
 	}
 	cout << res << endl;
    return 0;
}