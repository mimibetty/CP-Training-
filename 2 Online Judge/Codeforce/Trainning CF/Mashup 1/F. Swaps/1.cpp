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

int a[100005];
int b[100005];

int vt[200005];
int res[200005];
// int vt2[100005];

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
 		set<int>s;

 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 			vt[a[i]] = i;
 		}
 		for (int i = 1; i <= n; i++) {
 			cin >> b[i];
 			vt[b[i]] = i;
 			s.insert(i);
 		}
 		// cout<<  1 + 2*(n-1);

 		for (int i = 1; i <= 1 + 2*(n-1); i += 2) {
 			res[i] = *s.begin();
 			s.erase(s.find(vt[i+1]));
 			// cout << i << ' ' << res[i] << endl;
 		}
 		int ans = 1e9;
		for (int i = 1; i <= 1 + 2*(n-1); i += 2) {
 			ans = min(ans, vt[i]-2 + res[i]);
 			res[i] = 0; 
 		} 		
 		cout << ans << endl;

 		s.clear();
 		for (int i = 1; i <= 2*n; i++) vt[i] = 0;
 	}
    return 0;
}