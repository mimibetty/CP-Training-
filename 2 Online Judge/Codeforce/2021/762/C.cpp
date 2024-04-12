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
	ll a,s;
	cin >> a >> s;
	vector<int>b;

	// if (a > s) {
	// 	cout << -1 << endl;
	// 	return;
	// }
	// if (a == s) {
	// 	cout << 0 << endl;
	// 	return;
	// }
	while (s) {
		int x = a%10;
		int y = s%10;
		
		if (y - x >= 0) b.pb(y-x);
		else {
			s /= 10;
			y += 10 * (s%10);
			if (y - x >= 0 && y - x <= 9) {
				b.pb(y-x); 
			}
			else {
				cout << -1 << endl;
				return;
			}

		}
		a/= 10;
		s/= 10;
	}
	if (a) {
		cout << -1 << endl;
		return;
	}
	else {
		while(b[b.size()-1] == 0) b.pop_back();
		for (int i = b.size()-1; i >= 0; i--) cout << b[i];
		cout << endl;
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