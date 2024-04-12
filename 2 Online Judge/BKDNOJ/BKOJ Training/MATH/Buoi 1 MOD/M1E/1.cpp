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
 
ll a,b,c,m;	

ll pw(ll a,ll b) {
	ll res;
	if (b == 0) return 1;
	if (b ==1 ) return a;

	ll q = pw(a,b/2);
	if (b % 2== 0) res = q%m * q%m;
	else res = q%m * q%m *a ;
	return res % m;
} 
long long d, x, y;
void extendedEuclid(long long A, long long B) {
	if(B == 0) {
		d = A;
		x = 1;
		y = 0;
	}
	else {
		extendedEuclid(B, A%B);
		long long temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}

long long modInverse(long long A, long long M)	{
	extendedEuclid(A,M);
	return (x%M+M)%M; //x may be negative
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    cin >> a >> b >> c >> m;
	cout << (pw(a,b)* modInverse(c,m)%m)%m;

    return 0;
}