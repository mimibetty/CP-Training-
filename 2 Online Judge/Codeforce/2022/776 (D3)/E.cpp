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
	int n, d;
	cin >> n >> d;
	vector<int>a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(All(a));
	// for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	// cout << endl;
	int minval = 1e9, vt;
	for (int i = n; i >= 1; i--) {
		if (a[i] - a[i-1] - 1 < minval) {
			minval = a[i] - a[i-1] - 1;
			vt = i;
		}
	}
	cout << minval << ' ' << a[vt] << endl;
	// sau khi bo vt
	int minm = 1e9, maxm = 0;
	for (int i = 1; i <= n; i++) {
		if(i == vt) continue;
		if(i == vt+1) {
			minm = min(minm, a[i] - a[i-2] - 1);
			maxm = max(maxm, a[i] - a[i-2] - 1);
			
			continue;
		} 
		minm = min(minm, a[i] - a[i-1] - 1);
		maxm = max(maxm, a[i] - a[i-1] - 1);
	}
	cout << minm << ' ' << maxm << endl;
	int x = n;
	if (vt == a[n]) x--;

	int r1,r2;
	r1 = d - a[x] - 1;
	r2 = (maxm-1)/2;
	cout << "R1 R2 : " <<r1 << ' ' <<r2 << endl;
	cout << min(max(r1,r2),minm) ;
	cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
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