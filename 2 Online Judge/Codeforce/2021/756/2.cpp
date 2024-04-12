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
 
int check(int a,int b, int mid) {
	int minval = min(a,b);
	int maxval = max(a,b);
	
	maxval = maxval - (3*mid);
	minval = minval - mid;
	cout << minval << ' ' << maxval << ' '<< abs(maxval-minval) << endl;
	if (maxval > 0 && minval > 0 && abs(maxval - minval) > 2) return 1;

	// if ((maxval > 0) && (minval > 0) && (abs(maxval-minval) > 2)) return 1;
	return 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	// cout << check(5,8,0);
 	int t;
 	cin >> t;
 	while (t--) {
 		long long a,b;
 		cin >> a >> b;
 		if (a < b) swap(a,b);
 		// int maxval = max(a,b);
 		int res = 0;
 		
 		long long uper, lower,mid;
 		lower = 0, uper = max(a,b);
 		while (lower < uper) {
 			if (max(a,b) == a) swap(a,b); 
 			mid = (lower + uper) / 2;

 			if (check(a,b,mid) == 1) lower = mid+1;	
 			else {
 				uper = mid;
 			}
 			// cout <<lower << ' ' << uper << ' '<< mid << ' '<< check(a,b,mid)<< endl;
 		}
 		cout << endl;
 		cout << lower << ' ' << endl;
 		cout <<check(a,b,lower) << endl ;
 		// if (check(a,b,lower) == 0) lower--;
 		res += lower;
 		res += min((a/2), (b/2));
 		cout << endl;
 		cout << res << endl;
	

	// int minval = min(a,b);
	// int maxval = max(a,b);
	// cout << a << ' ' << b << endl;
	// maxval = maxval - (3*lower);
	// minval = minval - lower;
	// cout << maxval << ' ' << minval << ' ' << abs(maxval - minval);
	// cout << endl;
	// cout << check(1,10,1);
 	}
    return 0;
}