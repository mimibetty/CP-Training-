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
 
pair<int,int> a[200005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;

 	vector<int>x1;
 	vector<int>x2;
 	
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i].fi;
 	}
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i].se;
 	}

 	for (int i = 1; i <= n; i++) {
 		x1.pb(a[i].fi - a[i].se);
 		x2.pb(a[i].se - a[i].fi);
 	}

 	// for (int i)
 	sort(x1.begin(),x1.end());
 	sort(x2.begin(),x2.end());

 	long long res = 0;
 	for (int i = 1; i <= n; i++) {
 		auto q = upper_bound(x2.begin(),x2.end(),a[i].fi - a[i].se -1) - x2.begin();
 		// cout << i << endl;
 		// cout << q << ' ';
 		// if (x2[q] > a[i].fi - a[i].se) q--;
 		res += q;
 		// cout << q << ' ' << endl;
 		if (a[i].fi - a[i].se > a[i].se - a[i].fi) res--;
 		// cout << i << ' '<< q << ' ' << res << endl;
 	}
 	
 	cout << res/2 << endl;
 	// for (auto i : x1) cout << i << ' '; 
 	// 	cout << endl;
 	// for (auto i : x2) cout << i << ' '; 
 	// 	cout << endl;
    return 0;
}