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
const ll MOD = (long long)  (1e9+7);
const double PI = acos(-1);
 // dp[vi tri] [mu 2] [mu 3] [mu5] = so luong cach tao nen 2^a * 3^b * 5^c;
long long dp[105][65][45][35]; 

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long n,m;
 	cin >> n >> m;

 	long long x = m;
 	long long fac2 = 0, fac3 = 0, fac5 = 0;
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
 	
 	if (x != 1) {
 		cout << 0 << endl;
 		return 0;
 	}


 	dp[0][0][0][0] = 1;
 	for (int i = 1; i <= n; i++) {
 		for (int f2 = 0; f2 <= fac2; f2++) {
 			for (int f3 = 0; f3 <= fac3; f3++) {
 				for (int f5 = 0; f5 <= fac5; f5++) {
 					dp[i][f2][f3][f5] += dp[i-1][f2][f3][f5];  // BOC SO 1
 	
 					if (f2 >= 1) dp[i][f2][f3][f5] += dp[i-1][f2 - 1][f3][f5]; // boc so 2
 					dp[i][f2][f3][f5] %= MOD;
 	
 					if (f3 >= 1) dp[i][f2][f3][f5] += dp[i-1][f2][f3 - 1][f5];  // boc so 3
 					dp[i][f2][f3][f5] %= MOD;
 	
 					if (f2 >= 2) dp[i][f2][f3][f5] += dp[i-1][f2 - 2][f3][f5]; // boc so 4
 					dp[i][f2][f3][f5] %= MOD;
 	
 					if (f5 >= 1) dp[i][f2][f3][f5] += dp[i-1][f2][f3][f5 - 1]; // boc so 5
 					dp[i][f2][f3][f5] %= MOD;
 	
 					if (f2 >= 1 && f3 >= 1) dp[i][f2][f3][f5] += dp[i-1][f2 - 1][f3 - 1][f5]; // boc so 6 					
 					dp[i][f2][f3][f5] %= MOD;
 					
 					// cout << i << ' ' << f2 << ' ' << f3 << ' ' << f5 << ' ' << dp[i][f2][f3][f5] << endl;
 				}
 			}
 		}
 	}
 	cout << dp[n][fac2][fac3][fac5] << endl;
    return 0;
}