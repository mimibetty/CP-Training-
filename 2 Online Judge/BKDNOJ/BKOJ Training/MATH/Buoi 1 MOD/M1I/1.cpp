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
 
int a[55];
ll pw(ll a,ll b) {
	ll res;
	if (b == 0) return 1;
	if (b ==1 ) return a;

	ll q = pw(a,b/2);
	if (b % 2== 0) res = q%MOD * q%MOD;
	else res = q%MOD * q%MOD *a ;
	return res % MOD;
} 
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;
 	int gcd = 0;
 	for (int i =1; i <= n; i++) {
 		cin >> a[i];
 		gcd = __gcd(gcd,a[i]);
 	}
 	ll res = 1;
 	for (int i =1; i <= n; i++) {
 		res *= (pw(a[i],gcd));
 		res %= MOD;
 	}
 	// cout <<pw(12,4) << endl;
 	// cout << gcd << endl;
 	cout << res;
    return 0;
}