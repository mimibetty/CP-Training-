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

 		// vector<string>s(n);
 		for (int i = 1; i <= n-2; i++) {
 			cin >> s[i];
 		}

 		if (n == 3) {
 			cout << s[1] << 'a'<< endl;
 			continue;
 		}
 		bool check = 0;
 		cout << s[1];

 		for (int i = 2; i <= n-2; i++) {
 			if (check == 1) {
 				cout << s[i][1];	
 				continue;
 			}  

 			if (s[i][0] == s[i-1][1]) cout << s[i][1];
 			else {
 				check = 1;
 				cout << s[i];
 			}
 			// cout << i << endl;
 		}
 		if (check == 0) cout << 'a';
 		cout << endl;
 		for (int i = 1; i <= n; i++) s[i].clear();

 	}
    return 0;
}