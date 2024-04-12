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
 
struct inf{
	ll w,vt,idx;
};
bool cmp (inf a, inf b) {
	if (a.w == b.w) {
		return a.vt < b.vt;
	}
	else return a.w < b.w;
}

inf a[200005];
void solve() {
	int n,m;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].vt >> a[i].w;
		a[i].idx = i;
 	}
 	sort(a + 1, a+1+m,cmp);
 	vector<pair<ll,ll>>res; // vt,index
 	for (int i = 1; i <= 2*n; i++) {
 		sum += a[i].w;
 		res.pb({a[i].vt,a[i].idx});
 	}
 	sort(res.begin(),res.end());

 	cout << sum << endl;
 	// for(auto i : res) {
 	// 	cout << i.fi << ' ' << i.se << endl;
 	// }

 	for (int i = 0; i < n; i++) {
 		cout << res[i].se << ' ' << res[2*n-1-i].se << endl;
  	}
  	cout << endl;
 	// for (int i = 1; i <= m; i++) cout << a[i].w << ' ' << a[i].vt << ' ' << a[i].idx << endl;
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