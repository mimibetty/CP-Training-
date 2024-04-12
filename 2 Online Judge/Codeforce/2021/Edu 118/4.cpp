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
 
int n;
long long a[105];
int solve(long long mid, long long h) {
	long cnt = 0;
	for (int i = 1; i < n; i++) {
		long long d = a[i] + mid - 1;
		if (d < a[i+1]) cnt += mid;
		else if (d == a[i+1]) {
			cnt += d - a[i] + 1;
		}
		else {
			cnt += a[i+1] - a[i];
		}
	}
	cnt += mid;
	// return cnt;
	if (cnt >= h) return 1;
	else return 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		long long h;
 		cin >> n >> h;

 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 		}

 		long long mid =3 ;
 		long long cnt = 0;
		cnt += mid;
		cnt -=h;
		for (int i = 1; i < n; i++) {
			long long d = a[i] + mid - 1;
			if (d < a[i+1]) cnt += mid;
			else if (d == a[i+1]) {
				cnt += d - a[i] + 1;
			}
			else {
				cnt += a[i+1] - a[i];
			}
		}
		cout << cnt << endl;
		cout << solve(3,h);
 		// long long lower = 1,  uper = 1e18;
 		// long long mid = (lower + uper) / 2;
 		// while (lower < uper) {
 		// 	mid = (lower + uper) /2;
 		// 	if (solve(mid,h) == 1) uper = mid;
 		// 	else lower = mid + 1;

 		// 	// cout << mid << endl;
 		// }
 		// cout << lower << endl;
 	}
    return 0;
}