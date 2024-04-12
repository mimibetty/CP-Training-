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
 
int a[1005];
int b[1005];
int c[1005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		int n,w;
 		cin >> n >> w;
 		long long res = 0;
 		map<int,int>d1,d2,d3;
 		for (int i =1; i <= n; i++) {
 			cin >> a[i];
 			d1[a[i]]++;
 		}
 		for (int i =1; i <= n; i++) {
 			cin >> b[i];
 			d2[b[i]]++;
 		}
 		for (int i =1; i <= n; i++) {
 			cin >> c[i];
 			d3[c[i]]++;
 		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);

		if (w == 1) {
			set<int>aa;
			long long res1 = 0;
			for (int i = 1; i <= n; i++) {
				if (d1[a[i]] > 0 && d2[a[i]] > 0 && d3[a[i]] > 0) aa.insert(a[i]);
			}
			for (auto i : aa) res1 += 1ll * d1[i] * d2[i] * d3[i];
			cout << res1 << endl;
			aa.clear();
		}
		else if (w == 2) {
			ll res2 = 0;
			set<int>same12,same13,same23;
			
			for (int i = 1; i <= n; i++) {
				if (d1[a[i]] > 0 && d2[a[i]] > 0) same12.insert(a[i]);
				if (d1[a[i]] > 0 && d3[a[i]] > 0) same13.insert(a[i]);
			}
			for (int i = 1; i <= n; i++) {
				if (d2[b[i]] > 0 && d3[b[i]] > 0) same23.insert(b[i]);
			}

			// cout << 1222222 << endl;
			for (auto i : same12) {
				// cout << i << ' ';
		 		auto q = lower_bound(c + 1, c + 1 + n,(2*i)) - c - 1;
		 		q = max(0ll,q);
		 		// cout << q<< endl;
		 		res2 += 1ll * d1[i]* d2[i] * q;
			}
			// cout << 13333333 << endl;
			for (auto i : same13) {
				// cout << i << ' ';
		 		auto q = lower_bound(b + 1, b + 1 + n,(2*i)) - b - 1;
		 		q = max(0ll,q);
		 		// cout << q<< endl;
		 		res2 += 1ll * d1[i]* d3[i] * q;
			}
			// cout << 23333 << endl;
			for (auto i : same23) {
		 		// cout << i << ' ';
		 		auto q = lower_bound(a + 1, a + 1 + n,(2*i)) - a - 1;
		 		q = max(0ll,q);
		 		// cout << q<< endl;
		 		res2 += 1ll * d2[i] * d3[i] * q;
			}

			set<int>aaa;
			for (int i = 1; i <= n; i++) {
				if (d1[a[i]] > 0 && d2[a[i]] > 0 && d3[a[i]] > 0) aaa.insert(a[i]);
			}

			for (auto i : aaa) res2 -= 2ll*d1[i]*d2[i]*d3[i];
			cout << res2 << endl;
			aaa.clear();
			same23.clear();
			same13.clear();
			same12.clear();
		}
		else {
			long long res3 = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					long long val1 = abs(a[i] - b[j]);
					long long val2 = a[i] + b[j];
					auto l = upper_bound(c + 1, c + 1 + n,val1) - c;
					auto r = lower_bound(c + 1, c + 1 + n,val2) - c - 1;
					
					res3 += r-l+1;
				}
			}
			cout << res3 << endl;
		}
		d1.clear();
		d2.clear();
		d3.clear();
 	}
 	// cout << combi3(3);
    return 0;
}