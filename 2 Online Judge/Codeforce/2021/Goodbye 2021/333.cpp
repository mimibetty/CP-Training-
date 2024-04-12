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
 
double a[75];
double b[75];
void solve() {
	int n ;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1 || n == 2) {
		cout << 0 << endl;
		return;
	}
	int res = 1e9;
	for (int i = 1;i <= n; i++) {
		b[i] = a[i];
		vector<double>dis;

		for (int j = i + 1; j <= n; j++) { // tim 
			double z = 1.00 * (a[j] - a[i]) /  (j-i);
			dis.pb(z);
		}
		for (auto d : dis) {
			int cnt = 0;
			for (int x = i - 1; x > 0; x--) {
				b[x] = b[x+1] - d;
			}

			for (int x = i + 1; x <= n; x++) {
				b[x] = b[x-1] + d;
			}

			for (int x = 1; x <= n; x++) if(abs(b[x] - a[x]) > 1e-9) cnt++;
			res = min(res,cnt);
		}
	}
	cout <<res << endl;
}
int main() {
    // freopen("input.txt", "r", stdin);
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