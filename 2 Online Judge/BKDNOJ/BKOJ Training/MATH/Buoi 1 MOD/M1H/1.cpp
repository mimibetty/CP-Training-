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
const ll MOD = ll(1e9)+7;
const double PI = acos(-1);
 
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		ll n;
		cin >> n;
		n--;
		ll num = n*(n-1)/2;
		ll big = 1;
		ll small = 0;

		ll a,b,c;
		a = n;
		b = n+1;
		c = (2*n) + 1;
		if (a % 2 == 0) a/=2;
		else if (b % 2 == 0) b/=2;
		else c/=2;
		
		if (a % 3 == 0) a/=3;
		else if (b % 3 == 0) b/=3;
		else c/=3;
		// cout << a << ' ' << b << ' ' << c << endl;
		big = (a%MOD);
		big%=MOD;
		big *= (b%MOD);
		big%=MOD;
		big *= (c%MOD);
		big%=MOD;

		n++;
		num = n*(n-1)/2;
		ll numSmall = num/n;
		ll plus = num%n;
		ll part1 = 0;
		ll part2 = 0;
		// sD)%MOD;
			part1 = (numSmall+1);
			part1 %= MOD;
			part1 *= (numSmall+1);
			part1 %= MOD;
			part1 *= (plus%MOD);
			part1 %= MOD;

			part2 = (numSmall%MOD);
			part2 %= MOD;
			part2 *= (numSmall%MOD);
			part2 %= MOD;
			part2 *= (n-plus+MOD)%MOD;
			part2 %= MOD;
		small = (part2%MOD )+ (part1%MOD);
		small %=MOD;
		
		cout << small << ' ' <<big << endl;
 	}
    return 0;
}