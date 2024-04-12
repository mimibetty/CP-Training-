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
 
ll pw(ll a, ll b,ll mod) {
	if (b == 0) return 1;
	if (b == 1) return a%mod;

	ll q = pw(a,b/2,mod)%mod;
	ll res = 1;
	if (b % 2 == 0) {
		res *= q;
		res %= mod	;
		res *= q;
		res %= mod;	
	}
	else {
		res *= q;
		res %= mod;
		res *= q;
		res %= mod;
		res *= a;
		res %= mod;
	}	
	return res%mod;
}


int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	scanf("%d", &t);

 	while(t--) {
 		ll a,d,p;	
 		scanf("%lld %lld %lld", &a,&d,&p);

 		a %= p;
 		d %= p;
 		ll res = (-a%p + p)%p; 
 		ll q = pw(d,p-2,p)%p;
 		res = res%p * q%p;
 		res %= p;

 		if ((a%p + (res%p * d%p)%p)%p == 0) printf("%lld\n", res);
 		else printf("-1\n");
 	}
    return 0;
}