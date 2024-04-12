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
 
// pair<int,int>a[105];
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while(t--) {
 		map<int,int>d2;
 		int n;
 		cin >> n;
 		vector<pair<int,int>>a(n+1);
 		vector<int>b(n+1);

 		for (int i = 1; i <= n; i++) {
 			cin >> a[i].fi;
 			a[i].se = i;
 		}
 		for (int i = 1; i <= n; i++) {
 			cin >> b[i];
 			d2[b[i]]++;
 		}
 		sort(All(a));
		vector<int>stt;

 		int maxval = -1;
 		bool check = 1;
 		for (int i = 1; i <= n; i++) {
 			if (d2[a[i].fi] > 0) d2[a[i].fi]--;
 			else {
 				if (d2[a[i].fi + 1] > 0) {
 					d2[a[i].fi + 1]--;
 					stt.pb(a[i].se);
 					maxval = max(maxval,a[i].se);
 				}
 				else {
 					d2.clear();
			 		stt.clear();
 					cout << "NO" << endl;
 					check = 0;
 					break;
 				}
 			}
 		}
 		// for (auto i : a) cout <<  i.fi << ' ' << i.se <<endl;
 		// 	cout << endl;
 		// return 0;
 		// for (auto i : stt) cout << i << ' ';
 		// 	cout << endl;
 		// return 0;
 		// cout << maxval << ' ' << stt.size() << endl;
 		

 		if (check == 0) continue;
 		if (maxval == -1)  cout << "YES" << endl;
 		else {
 			if (maxval == stt.size()) cout << "YES";
 			else cout << "NO";
 			cout << endl;
 		}
 		d2.clear();
 		stt.clear();
 	}
    return 0;
}