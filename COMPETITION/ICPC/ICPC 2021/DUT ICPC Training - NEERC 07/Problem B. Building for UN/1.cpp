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
 
char a[20][20];
int main() {
	  freopen("building.in","r",stdin);
    freopen("building.out","w",stdout);
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	vector<pii>vt;
 	vt.pb({1,1});
 	vt.pb({16,1});
 	vt.pb({1,16});
 	vt.pb({16,16});

 	vector<char>ch;
 	for (char i = 'a'; i <= 'z'; i++) ch.pb(i);
 	for (char i = 'A'; i <= 'A' + 23; i++) ch.pb(i);

 	// cout << ch.size();
 	// for (auto i : ch) cout << i << ' ';
 	// 	cout << endl;

 	
 	int n;
 	cin >> n;

 	cout << n << ' ' << 16 << ' ' << 16 << endl;
 	for (int z = 0; z < n; z++) {

	 	int cnt = 0;
	 	for (int i = 1; i <= 16; i++) {
	 		if (i == 16) {
	 			a[1][i] = a[1][i-1];
	 			continue;
	 		}
	 		bool ok = 1;
	 		for (auto j : vt) {
	 			if (j.fi == 1 && j.se == i) {
	 				ok = 0;
	 				break;
	 			}
	 		}
	 		if (ok == 0) {
	 			a[1][i] = ch[cnt];
	 			continue; 
	 		}
	 		a[1][i] = ch[cnt];
	 		cnt++;
	 		if (cnt == n) cnt = 0;
	 	} 

	 	for (int i = 2; i <= 16; i++) {
	 		if (i == 16) {
	 			a[i][16] = a[i-1][16];
	 			continue;
	 		}
	 		bool ok = 1;
	 		for (auto j : vt) {
	 			if (j.fi == i && j.se == 16) {
	 				ok = 0;
	 				break;
	 			}
	 		}
	 		if (ok == 0) {
	 			a[i][16] = ch[cnt];
	 			continue; 
	 		}
	 		a[i][16] = ch[cnt];
	 		cnt++;
	 		if (cnt == n) cnt = 0;
	 	} 

		for (int i = 2; i <= 16; i++) {
	 		if (i == 16) {
	 			a[16][i] = a[16][i-1];
	 			continue;
	 		}
	 		bool ok = 1;
	 		for (auto j : vt) {
	 			if (j.fi == 16 && j.se == i) {
	 				ok = 0;
	 				break;
	 			}
	 		}
	 		if (ok == 0) {
	 			a[16][i] = ch[cnt];
	 			continue; 
	 		}
	 		a[16][i] = ch[cnt];
	 		cnt++;
	 		if (cnt == n) cnt = 0;
	 	} 

		for (int i = 2; i <= 16; i++) {
	 		if (i == 16) {
	 			a[i][1] = a[i-1][1];
	 			continue;
	 		}
	 		bool ok = 1;
	 		for (auto j : vt) {
	 			if (j.fi == i && j.se == 1) {
	 				ok = 0;
	 				break;
	 			}
	 		}
	 		if (ok == 0) {
	 			a[i][1] = ch[cnt];
	 			continue; 
	 		}
	 		a[i][1] = ch[cnt];
	 		cnt++;
	 		if (cnt == n) cnt = 0;
	 	} 



 		for (int i = 1; i <= 16; i++) {
 			for (int j = 1; j <= 16; j++) {
 				if (i == 1 || i == 16 || j == 1 || j == 16) continue;
 				a[i][j] = ch[z];
 			}
 		}

 		for (int i = 1; i <= 16; i++) {
 			for (int j = 1; j <= 16 ;j++) cout <<a[i][j];
 				cout << endl;
 		}
 		cout << endl;
 	}
 	
    return 0;
}