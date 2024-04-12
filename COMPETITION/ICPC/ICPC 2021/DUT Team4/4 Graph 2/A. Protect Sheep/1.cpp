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
 
char a[505][505];
int n,m;
bool check(int x,int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m) return 1;
	return 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

 	cin >> n >> m;
 	vector<pair<int,int>>posW;
 	for (int i = 1; i <= n ;i++) {
 		for (int j = 1; j <= m ;j++) {
 			cin >> a[i][j];
 			if (a[i][j] == 'W') posW.pb({i,j}); 
 		}
 	}


 	for (int i = 1;  i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			if (a[i][j] != 'S') continue;
 			for (int z = 0; z < 4; z++) {
 				int vt1 = i + dx[z];
 				int vt2 = j + dy[z];
 				if (check(vt1,vt2)) {
 					if (a[vt1][vt2] == '.') a[vt1][vt2] = 'D';	
 				} 
 			}
 		}
 	}

 	for (auto i : posW) {
 		// cout << i.fi << ' ' << i.se <<endl;
 		for (int d = 0; d < 4; d++) {
 				int vt1 = i.fi + dx[d];
 				int vt2 = i.se + dy[d];
 				if (check(vt1,vt2)) {
 					if (a[vt1][vt2] == 'S') {
 						cout << "No" << endl;
 						return 0;
 					}
 				}
 			}
 	}

 	cout << "Yes" << endl;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) cout << a[i][j];
 		cout << endl;
 	}
 	// cout <<<<endl;
    return 0;
}