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
 
int cnt[1000005];
int cnt2[1000005];
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		cnt[a]++;

	}	
	for (int i = 1; i <= 1e6; i++) {
		for (int j = 1; j * i <= 1e6; j++) {
			cnt2[i] += cnt[i*j];
		}
	}

	int res = 0;
	for (int i = 1e6; i >= 1; i--) {
		if (cnt[i] == 1) continue;
		int x = 0;

		for (int j = 2; j*i <= 1e6; j++) {
			if (cnt[j*i] == 1) x++;
		}

		if (x >= 2) {	
			bool ok = 1;
			for (int j = 2; i * j <= 1e6; j++) {
				if (cnt2[i*j] == cnt2[i]) {
					ok = 0;
					break;
				} 
			}
			if (ok) res++;
			cnt[i]++;
		}
	}
	cout << res;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	solve();
    return 0;
}