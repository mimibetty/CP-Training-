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
 
long long pw(long long a, long long b,ll mod) {
    if (b == 1) return a;
    if (b == 0) return 1;
    long long q = pw(a, b/2, mod) % mod;
    if (b % 2 == 0) return q%mod * q%mod;
    else return q%mod * q%mod * a%mod; 
}

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
 		// ans = 1/2^(n-1) 

 		ll surplus = pw(2,(n-1), MOD);
 		ll res = pw(surplus,(MOD-2),MOD);
 		cout << res << endl;
 		
 	}
    return 0;
}