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
 
const long long MOD = (long long) 1e9 + 7; 

long long fact[105], inv[105];
long long pw(long long a, long long b, long long p) {
	if (b == 0 ) return 1;

	long long q = pw(a, b/2, p);
	long long res = 1; 

	if (b % 2 == 0) res = q * q % p;
	else res = q * q % p * a % p;

	return res;
}

void do_combi() {
	fact[0] = 1;
	inv[0] = 1;

	for (int i = 1; i <= 100; i++) {
		fact[i] = fact[i-1] * i % MOD;
	}
	inv[100] = pw(fact[100], MOD - 2, MOD);
	for (int i = 100-1; i >= 1; i--) {
		inv[i] = inv[i+1] * (i+1) % MOD;
	}
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long n,m;
 	cin >> n >> m ;

 	int fac2 = 0, fac3 = 0 , fac5 = 0;
 	long long x = m;
 	while (x % 2 == 0) {
 		x /= 2;
 		fac2++;
 	}
 	while (x % 3 == 0) {
 		x /= 3;
 		fac3++;
 	}
 	while (x % 5 == 0) {
 		x /= 5;
 		fac5++;
 	}

 	if (x > 1) {
 		cout << 0 << endl;
 		return 0;
 	}

 	long long res = 0;
 	do_combi();
 	// for (int f4 = 0; f4 <= n; f4++) {
		// for (int f6 = 0; f6 <= n; f6++) {
 	for (int f6 = 0; f6 <= fac3; f6++) {
 		for(int f4 = 0; 2*f4 + f6 <= fac2; f4++) {
 			int x6 = f6, x4 = f4;
 			int x5 = fac5;
 			int x2 = fac2 - 2*x4 - x6;
 			int x3 = fac3 - x6;
 			int x1 = n - x2 - x3 - x4 - x5 - x6;
 			// int x1 = n - fac2 - fac3 - fac5 + x4 + x6;
 			if(x1 < 0 || x2 < 0 || x3 < 0) continue;
 			if(x4 + x6 < fac2 + fac3 + fac5 - n) continue;
 			long long aa = fact[n] % MOD;
 			aa = aa * inv[x1] % MOD * inv[x2] % MOD * inv[x3] % MOD * inv[x4] % MOD * inv[x5] % MOD * inv[x6] % MOD; 

 			res += aa;
 			res %= MOD;
 		}
 	}
 	cout << res << endl;
    return 0;
}