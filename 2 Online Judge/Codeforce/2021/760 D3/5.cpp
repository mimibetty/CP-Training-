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
 
ll a[400005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
 		long long sum = 0;
 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 			sum += a[i];
 		}
 		
 		long long num = n*(n+1)/2;
 		if (sum % num != 0) {
 			cout << "NO" << endl;
 			continue;
 		}
 		else {
 			long long tonga = sum/num;
 			// cout << tonga << endl;
 			bool check = 0;
 			if (tonga >= n) {
	 			long long x = tonga;
	 			// cout << "YES" << endl;

	 			for (int i = 1; i <= n; i++) {
	 				if (i == 1) {
	 					if (( - a[1]  + a[n] + tonga) % n != 0 || (a[1] -a[n] - tonga) / (-n) <= 0) {
	 						check = 1;
	 						break;
	 					}
	 					// cout << ((a[1] -a[n] - tonga) / -n) << ' ';
	 				}
	 				else {
	 					if (( -a[i]  + a[i-1] + tonga) % n != 0 || (a[i] -a[i-1] - tonga) / (-n) <= 0) {
	 						check = 1;
	 						break;
	 					}
	 					// cout << ((a[i] -a[i-1] - tonga) / -n) << ' '; 
	 				}
	 			}
	 			if (check == 1) cout << "NO" << endl;
	 			else {
	 				cout <<"YES" <<endl;
	 				for (int i = 1; i <= n; i++) {
		 				if (i == 1) {
		 					cout << ((a[1] -a[n] - tonga) / (-n)) << ' ';
		 				}
		 				else {
		 					cout << ((a[i] -a[i-1] - tonga) / (-n)) << ' '; 
		 				}
		 			}	
	 			}
	 			cout << endl;
 			} 
			else cout << "NO" << endl;
 		}
 	}
    return 0;
}