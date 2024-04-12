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
 
int a[200005];
ll ps[200005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		long long s;
 		cin >> n >> s;
 		bool check = 0;
 		for (int i =1;  i<= n; i++) {
 			cin >> a[i] ;
 			if (s + a[i] >= 0) check = 1;
 			ps[i] = ps[i-1] + a[i];
 			// cout << ps[i] << ' ';
 		}
 		// cout << endl;

 		if (check == 0) {
 			cout << -1 << endl;
 			continue;
 		}

 		int first,last;
 		int res = -1;
 		for (int i = 1; i <= n; i++) {
 			int lower = i-1, upper = n;
	        while (lower < upper) {
	            int mid = (lower + upper) / 2;

	            if (ps[mid] - ps[i - 1] + s >= 0) {
	                lower = mid + 1;
	            }
	            else {
	                upper = mid;
	            }
	        }
	        if (ps[lower] - ps[i-1] + s < 0) lower--; 
	        // cout << i << ' ' << lower << ' ' <<ps[lower] - ps[i - 1] + s << endl; 
	        if (res < (lower-i+1)) {
	        	res = lower-i+1;
	        	first = i;
	        	last = lower;
	        }
 		}
 		// cout<<ps[4] - ps[2 - 1] + s<<endl;
 		// cout << res << endl;
 		cout << first << ' ' << last << endl;
 	}
    return 0;
}