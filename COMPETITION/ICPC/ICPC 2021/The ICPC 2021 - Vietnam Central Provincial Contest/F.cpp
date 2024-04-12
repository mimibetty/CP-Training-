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
 
long long aa[300];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		string s;
 		vector<int>a[35];
 		cin >> s;
 		int n = s.size();
 		for (int i = 0; i < 30; i++) {
 			a[i].pb(0);
 		}
 			// cout << n << endl;
 		for (int i = 0; i < n; i++) {
 			int x = (int)(s[i] - 'a');
 			a[x].pb(i+1);
 			// cout << x << ' ';
 		}

 		long long res = 0;
 		for (int i = 0 ; i <= 29; i++) {
 			a[i].pb(n+1);
 			if (a[i].size() == 2) continue;
 			int num = a[i].size();

 			for (int j = 0; j < num; j++) {
 				if (j == 0 || j == num - 1) {
					// res += abs(a[i][j] - a[i][j+1]);
					// aa[i] += abs(a[i][j] - a[i][j+1]);
 					// res += abs(a[i][j-1] - a[i][j]);
 				}
 				else {
					res += (abs(a[i][j] - a[i][j+1]))* (abs(a[i][j-1] - a[i][j]));	
 					aa[i] += 1ll*(abs(a[i][j] - a[i][j+1]))* (abs(a[i][j-1] - a[i][j]));
 				} 
 			}
 			// cout << char(i+'a') << ' ' << res << endl;
 		}

 		long long res1 = 0;	
 		for (int i = 0; i <= 30; i++) {
 			if (a[i].size() <= 2) {
				 continue;
 			}
 			res1 += aa[i];
 			// cout << char(i+'a') << ' ' << aa[i] << endl;
 		}

 		// cout << endl;
 		// int j = 1;
 		// cout <<(abs(a[0][j] - a[0][j+1]));
 		// cout << endl;

 		cout << res1;
 		cout << endl;
 		for (int i = 0; i <= 30; i++) {
 			a[i].clear();
 			aa[i] = 0;
 
 		}
 	}
    return 0;
}