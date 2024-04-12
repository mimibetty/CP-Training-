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

ll a[200005]; 
int n,k;
int check(ll mid) {
	ll sum = 0;
	int cnt = 1;
	ll maxval = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > mid) return 0;

		sum += a[i];
		if (sum > mid) {
			sum = a[i];
			cnt++;
		}
		else maxval = max(maxval,sum);

		if (cnt > k) return 0;
		// cout << i << ' ' << sum << ' ' << cnt <<endl;
	}
	// if(maxval == mid) return 1;
	// return 0;
	return maxval ;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++) cin >> a[i];

 	ll lower = 1, upper = 2e14;
 	ll mid;
 	while (lower < upper) {
 		mid = (lower + upper)/2;
 			
 		if (check(mid) != 0) upper = mid; 
 		else {
 			lower = mid + 1;
 		}
 	}

 	if (check(lower) == 0 && lower != 1) lower--;
 	cout << lower;
    // cout << check() << endl; 
    return 0;
}