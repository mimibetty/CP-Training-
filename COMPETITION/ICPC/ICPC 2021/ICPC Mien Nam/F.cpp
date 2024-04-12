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
 
long long Mod = 1e9+7;

long long pw(long long a, long long b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	long long p = pw(a,b/2) % Mod;
	long long res;

	if (b % 2 == 0) res = p%Mod * p%Mod;
	else res = p%Mod * p%Mod * a;
	return res % Mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	for (int i = 1; i <= 8; i++) {
 		
 	}
 	int n;
 	cin >> n;
 	set<int>s;
 	int gcd = 0;
 	for (int i =1; i <= n; i++) {
 		gcd = __gcd(i,gcd);
 		s.insert(gcd);
 		// cout << i << ' '<<gcd << endl;
 	}
 	long long num = s.size();
 	cout << num << endl;
 	// cout << pw(num,Mod-1) ;
    return 0;
}