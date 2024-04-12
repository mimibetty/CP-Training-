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
 
long long dp[505][505]; // dp (vi tri, di qua k diem) = so cach
long long x[2005], y[2005];
const long long MOD = (long long) 1e9 + 7;
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> x[i];
    }

    for (int i = 1; i <= n; i++) {
    	cin >> y[i];
    }

    for (int i = 1; i <= n; i++) dp[i][1] = 1;

	for (int k = 1; k <= n; k++) {
	    for (int i = 1; i <= n; i++) {
	    	for (int j = 1; j <= n; j++) {
    			if(i == j) continue;
    			if (x[j] > x[i] && y[j] < y[i]) { 
	    			dp[i][k] += dp[j][k-1];
	    			dp[i][k] %= MOD;
    			}
    		}
    	}
    }

    for (int i = 1; i <= n; i++) {
    	long long res = 0;
    	for (int j = 1; j <= n; j++) {
    	
    		res += dp[j][i];
    		res %= MOD;	
    		// cout << i << ' ' << j << ' '<<res << endl;
    	}  
   	 	cout << res << ' ';	
    } 

    return 0;
}