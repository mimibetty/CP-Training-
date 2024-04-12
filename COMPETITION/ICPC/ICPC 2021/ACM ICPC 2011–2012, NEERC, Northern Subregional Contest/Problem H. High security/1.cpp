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

bitset<5> bs;
string s[50005];
long long f[10];
long long combi[10][10];

long long c2(long long n) {
	return n * (n - 1) / 2;
}

void solve() {
	int n;
	cin >> n;
	map<string, long long> d[35];

	combi[0][0] = 1;
	for (int i = 1; i <= 10; i++) {
		combi[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			combi[i][j] = combi[i - 1][j] + combi[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> s[i];

		for (int bit = 0; bit < 32; bit++) {
			bs = bit;
			string cur;
			for (int j = 0; j < 5; j++) {
				if (bs[j] == 1) cur += s[i][j];
			}

			// if (cur.empty()) continue;

			d[bit][cur]++;
		}
	}

	for (int bit = 0; bit < 32; bit++) {
		int k = 5;
		bs = bit;
		for (int j = 0; j < 5; j++) {
			if (bs[j] == 1) k--;
		}

		for (auto i: d[bit]) { 
			f[k] += c2(i.second);
		}
	}

	// for (int i = 0; i <= 5; i++) {
	// 	cout << f[i] << ' ';
	// }
	// cout << endl;


	for (int k = 0; k <= 5; k++) {
		for (int i = 0; i < k; i++) {
			f[k] -= f[i] * combi[5 - i][5 - k];
			// if (k == 2) cout << f[i] << ' ' << 5 - i << ' ' << 5 - k << endl;
 		}
	}

	for (int k = 0; k <= 5; k++) {
		cout << f[k] << ' ';
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
    freopen("high.in", "r", stdin);
    freopen("high.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	solve();
    return 0;
}