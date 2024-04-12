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
 
long long a[200005];
int n;
int lim[200005];
int check(long long mid) {
	for (int i = n; i >= 3; i--) {
		if (a[i] <  mid) return 0;

		int dis = a[i] - mid;
		dis = (dis)/3;
		a[i] -= dis*3;
		a[i-1] += dis;
		a[i-2] += dis*2; 
	}

	ll minval = 1e9;
	for (int i = 1;i <= n; i++) {
		minval = min(minval,a[i]);
	}
	if (minval >= mid) return 1;
	return 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		cin >> n;
 		for (int i =1; i <= n; i++) cin >> a[i];

 		for (int i = 3; i <= n; i++) {
 			lim[i] = a[i]/3;
 		}
 		
 		int lower = 0,uper = 1e9;
 		while (lower < uper ) {
 			int mid = (uper + lower) / 2;
 			if (check(mid)) lower = mid;
 			else uper = mid;
 			cout << mid << endl;
 		}
 		cout << lower << endl;
 	}
    return 0;
}