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
 
int ps[10005];
bool snt(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n;i++) if (n % i == 0) return 0;

	return 1;

}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	ps[1] = 0;
    for (int i = 3; i <= 10000; i+=2) {
    	int num;
    	ps[i] = ps[i-2];
    	for (int j = 0; j <= 3; j++) {
    		num = i * i;
    		num -= j*(i-1);
    		// cout << i << ' ' << num << endl;
    		if (num > 0) {
    			if (snt(num) == 1) ps[i]++;
    		}
    	}
    	// cout << i << ' ' << ps[i] << endl;
    }

	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d", &n);

		double res = 1.000000 * 100 * ps[n] / (2*n-1);
		printf("%0.6f\n", res);
		// printf("%d", ps[n]);
	} 	
    return 0;
}