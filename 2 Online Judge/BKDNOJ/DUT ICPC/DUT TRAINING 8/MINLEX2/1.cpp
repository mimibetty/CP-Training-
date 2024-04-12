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
 

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long l,r,k;
 	while (cin >> l >> r >> k) {
 		vector<string>s;
 		long long x = 1;
 		
 		if (l < 10) {
 			long long res = (l + k - 1) /k * k;
 			if (res <= r) s.pb(to_string(res));
 		}

 		for (long long i = 1; i <= 9; i++) {
 			x *= 10;
 			long long val = max(x, l);
 			val = (val + k - 1) / k * k;
 			if (val <= r) {
	 			// cout << val << ' ' << x << endl;
 				s.pb(to_string(val));
 			}
 			else break;
 		}
 		sort(s.begin(), s.end());
 		// for (auto i : s) cout << i << endl;
 		
 		if(s.empty() == 1) cout << -1 << endl;
 		else cout << s[0] << endl;

 		s.clear();
 	}
    return 0;
}