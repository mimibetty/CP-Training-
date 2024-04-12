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
	string s;
	int n,m,d,k;
	cin >> n >> m >> d >> k;
	cin >> s;

	int l = -1, r = -1;
	int lenx = 0,  vt = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			if (l == -1) {
				l = i + 1;
				r = i + 1;
			}
			else r = i + 1;
		}
	}

	if (l == -1 && r == -1) {
		int cnt1 = k - 1;
		int cnt2 = n - k;

		if (cnt1 < d && cnt2 < d) cout << "Impossible\n";
		else {
			int dem = 0;
			if (cnt1 > d) dem += 2;
			else if (cnt1 == d) {
				if (m == d) dem++;
				else dem += 2;
			}

			if (cnt2 > d) dem += 2;
			else if (cnt2 == d) {
				if (m == d) dem++;
				else dem += 2;
			}

			if (dem == 1) cout << "Unique\n";
			else if (dem > 1) cout << "Ambiguous\n";
			else cout << "Impossible\n";
		}

		return;
	}

	for (int i = l; i <= r; i++) {
		if (s[i - 1] != '*') {
			cout << "Impossible" << endl;
			return;
		}
	}

	if (r - l + 1 != d) {
		cout << "Impossible" << endl;
		return; 
	} 

	int cnt = 0;
	int uper = 0, lower = 0;
	for (int i = k; i <= n; i++) {
		uper = i;
		lower = uper - d + 1;
		if (k >= lower && k <= uper && lower >= 1) cnt++;
	}

	if (cnt == 1) {
		cout << "Unique";
	}
	else if (cnt > 1) cout << "Ambiguous";
	else cout << "Impossible";
}

int main() { 
	    // freopen("input.txt", "r", stdin);

    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	solve();
    return 0;
}