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
 
pair<long long,long long>a[105];
int n;
long long m;

long long check(long long mid) {
	long long cnt = 0;

	for (long long i = 1; i <= n; i++) {
		long long nghi = mid/(a[i].se +1);
		long long lam = mid - nghi;
		if (lam > (m/a[i].fi)) return 1;
		if (cnt >= (m - (lam*a[i].fi)) ) return 1;
		cnt += lam*a[i].fi;
		if (cnt >= m) return 1;
	}

	if (cnt >= m) return 1;
	return 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i].fi >> a[i].se;
 	}

 	long long lower = 0, uper = 1e16;
 	while (lower < uper) {
 		long long mid = (lower + uper) /2;
 		if (check(mid) == 1) {
 			uper = mid;
 		}
 		else {
 			lower = mid+1;
 		}
 		// cout << mid << ' ' << check(mid) << endl;
 	}


 	cout << lower << endl;

 
    
    return 0;
}