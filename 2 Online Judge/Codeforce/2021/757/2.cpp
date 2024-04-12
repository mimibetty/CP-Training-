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
int cnt[1000005];
vector<int>aa[1000005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;

 	while(t--) {
 		int n;
 		cin >> n;
 		vector<int>exist;

 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 			if (cnt[a[i]] == 0) {
 				exist.pb(a[i]);
 			}
 			cnt[a[i]]++;
 		}

 		sort(exist.begin(),exist.end());
 		reverse(exist.begin(),exist.end());

 		int dem = 0;
 		int point = 0;
 		for (auto i : exist) {
 			for (int j = 1; j <= cnt[i]; j++) {
 				dem++;
 				if (dem % 2 == 1) {
	 				point++;
	 				aa[i].pb(point);
	 			}
	 			else aa[i].pb(-point);	
 			}
 		}

 		long long res = 0;
 		for (auto i : exist) {
 			// cout << i << endl;
 			for (auto j : aa[i]) {
 				// cout << j << ' ';
 				res += 2ll*i*abs(j);
 			}
 			// cout << endl;
 		}
 		cout << res << endl;
 		cout << 0 << ' ';
 		for (int i = 1; i <= n; i++) {
 			cout << aa[a[i]].back() << ' ';
 			aa[a[i]].pop_back();
 		}

 		cout << endl;
 		
 		for (auto i : exist) {
 			cnt[i] = 0;
 			aa[i].clear();
 		}
 		exist.clear();
 	}
    return 0;
}