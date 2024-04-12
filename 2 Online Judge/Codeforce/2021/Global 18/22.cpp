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
 
bitset<32>bs[200005]; 
int ps[200005][32];

void solve() {
	int l,r;
	cin >> l >> r;
	long long res = 1e9;
	long long num = r - l + 1;
	for (int i = 0; i <= 30; i++) {
		res = min(res,num - (ps[r][i] - ps[l-1][i]));
	}
	cout << res <<endl;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	// bs[1] = 13;
 	// cout << bs[1];
 	// cout << endl;
 	// for (int i = 0; i <= 31; i++) {
 	// 	cout << i << ' ' << bs[i][1] << endl;
 	// }
 	for (int i = 1; i <= 200000; i++) {
 		bs[i] = i;
 	}

 	for (int i = 1; i <= 200000; i++) {
 		for (int bit = 0; bit <= 30; bit++) {
 			ps[i][bit] = ps[i-1][bit] + bs[i][bit];
 		}
 	}

 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
 	// for (int i = 1; i <= 5; i++) {
 	// 	for (int j = 0; j <= 5; j++) {
 	// 		cout << i << ' ' << j << ' ' << ps[i][j] << endl; 
 	// 	}
 	// }
    return 0;
}