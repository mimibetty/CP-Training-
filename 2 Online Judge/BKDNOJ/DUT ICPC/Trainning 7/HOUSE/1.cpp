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
 
int a[100005], minval[100005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >>a[i];
	} 
	minval[n-1] = a[n];
	// minval
	int f = 1e9;
	for (int i = n-1; i >= 1; i--) {
		// minval[i] = min(minval)
		f = min(f,a[i+1]);
		minval[i] = f;
	}

	// for (int i = 1; i <= n; i++) cout << minval[i] << ' ';
	int res = -1e9;
	for (int i = 1; i < n; i++) {
		res = max(res, a[i] - minval[i]);
		// cout << a[i] - minval[i] << endl;
	}

	if (res >= 0) cout << res;
	else cout << "Lo nang roi!";

    return 0;
}