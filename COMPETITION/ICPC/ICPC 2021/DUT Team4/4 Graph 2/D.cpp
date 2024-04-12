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
 
string s[105];

void solve() {
 	int n;
 	cin >> n;
 	map<char,bool>dd;
 	for (int i = 1; i <= n; i++) cin >> s[i];
 	vector<char>res;
 	for (int i = 1; i < n; i++) {
 		int num = min(s[i].size(), s[i+1].size());

 		for (int j = 0; j < num; j++) {
 			if (j == num - 1) {
 				if (s[i][j] == s[i+1][j]) {
 					if (s[i].size() < s[i+1].size()) {
 						cout << "IMPOSSIBLE" << endl;
 						return;
 					}
 					continue;
 				}

 				if (dd[s[i][j]] == 1) {
 					
 					cout << "IMPOSSIBLE" << endl;
 					return;
 				}
				dd[s[i][j]] = 1;
				res.pb(s[i][j]);
 			}
 			else {
 				if (s[i][j] != s[i+1][j]) {	
 					
 					if (dd[s[i][j]] == 1) {
 						// for (auto jj : dd) cout << jj.fi << ' ' << jj.se << endl;
 						// cout << i << ' ' << j << ' ' << s[i][j] << endl;
	 					cout << "IMPOSSIBLE" << endl;
	 					return;
	 				}
					dd[s[i][j]] = 1;
					res.pb(s[i][j]);
					break;
	 			}
 			}
 		}  
 	}
 	if (n > 1) {
 	int num = min(s[n].size(), s[n-1].size());
 		for (int j = 0; j < num; j++) {
 			if (j == num - 1) {
 				if (s[i][j] == s[i+1][j]) {
 					if (s[n-1].size() > s[n].size()) {
 						cout << "IMPOSSIBLE" << endl;
 						return;
 					}
 					continue;
 				}

 				if (dd[s[n][j]] == 1) {
 					cout << "IMPOSSIBLE" << endl;
 					return;
 				}
				dd[s[i][j]] = 1;
				res.pb(s[i][j]);
 			}
 			else {
 				if (s[i][j] != s[i+1][j]) {	
 					
 					if (dd[s[i][j]] == 1) {
 						// for (auto jj : dd) cout << jj.fi << ' ' << jj.se << endl;
 						// cout << i << ' ' << j << ' ' << s[i][j] << endl;
	 					cout << "IMPOSSIBLE" << endl;
	 					return;
	 				}
					dd[s[i][j]] = 1;
					res.pb(s[i][j]);
					break;
	 			}
 			}
 		}  
 	}
 	for (char i = 'a'; i <= 'z'; i++) if (dd[i] == 0) cout << i;
 	for (auto i : res) cout << i;

}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	solve();

    return 0;
}