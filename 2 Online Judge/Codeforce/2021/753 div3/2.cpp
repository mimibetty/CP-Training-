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
 
 	int t;
 	cin >> t;
 	while (t--) {
 		ll n,x;
 		cin >> x >> n;
 		if (n == 0) {
 			cout << x << endl;
 			continue;
 		}
 		ll res = 0;
 		ll socap, socapduong, socapam,d1,d2,a1,a2;
 		a1 = 0 ;a2 = 0;
 		d1 = 0 ;d2 = 0;
 		ll pair_le ,pair_chan, am , duong;
 		if (x % 2 == 0) {
 			res = x - 1;

 			socap = (n-1)/2;
 			socapduong = socap/2;
 			socapam = socap/2;
 			if (socap % 2 != 0) socapduong++;
 			if (socapduong >= 1) {
 				d1 = 5;
	 			d2 = 5 + (socapduong-1)*8;	
 			} 

 			if (socapam >= 1) {
 				a1 = 9;
 				a2 = 9 + (socapam-1)*8;	
 			}

 			if ((n-1) % 2 != 0) {
 				if ((n-1) % 4 == 1 || (n-1) % 4 == 2) res += n;
 				else res -=n;
 			}
 			res += ((d1+d2)*socapduong/2) - ((a1+a2)*socapam/2);
 			
 		}
 		else {
 			res = x + 1;

 			socap = (n-1)/2;
 			socapduong = socap/2;
 			socapam = socap/2;
 			if (socap % 2 != 0) socapam++;
 			
 			if (socapam >= 1) {
 				a1 = 5;
	 			a2 = 5 + (socapam-1)*8;	
 			} 

 			if (socapduong >= 1) {
 				d1 = 9;
	 			d2 = 9 + (socapduong-1)*8;
 			} 

 			if ((n-1) % 2 != 0) {
 				if ((n-1) % 4 == 1 || (n-1) % 4 == 2) res -= n;
 				else res += n;
 			}
 			res += ((d1+d2)*socapduong/2) - ((a1+a2)*socapam/2);
 		}

 		// cout << socapduong << endl;
 		// cout << socapam << endl;
 		// 	cout << d1 << ' ' << d2<< endl;
 		// 	cout << a1 << ' ' << a2<< endl;
 		// 	cout << ((d1+d2)/2) <<endl;
 		// 	cout << ((a1+a2)/2) << endl;
 		cout << res << endl;
 	}
    return 0;
}