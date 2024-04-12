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
 
ll a[505][505];
ll ps2D[505][505];
 
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

 	int n,m;
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; i <= m; j++) {
 			cin >> a[i][j];
 			ps2D[i][j] = ps[i-1][j] + ps[i][j-1] + ps[i-1][j-1] + a[i][j];
 		}
 	}

 	ll minval = a[1][1];
 	ll res = a[1][1];
	for (int i = 1; i <= n; i++) {
 		for (int j = 1; i <= m; j++) {
 			res = max(res, ps2D[i][j] - minval)
 			ps2D[i][j] = ps[i-1][j] + ps[i][j-1] + ps[i-1][j-1] + a[i][j];
 		}
 	}

    return 0;
}