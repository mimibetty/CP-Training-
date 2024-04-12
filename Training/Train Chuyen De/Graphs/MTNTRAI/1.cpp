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
const int dx8[8] = {1,1,1,0,0,-1,-1,-1}, dy8[8] = {-1,0,1,-1,1,-1,0,1};

const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
int n,m;
bool vs[1005][1005];
char a[1005][1005];

int f = 0;
int c = 0;

bool check(int u, int v) {
	if (u >= 1 && u <= n && v >= 1 && v <= m && a[u][v] != '#') return 1;
	return 0;
}

void dfs(int u, int v) {
	vs[u][v] = 1;
	
	// cout << u << ' ' << v <<endl;
	for (int i = 0; i < 4; i++) {
		int x = u + dx[i];
		int y = v + dy[i];
		if (check(x,y) == 1) {
			if (vs[x][y] == 0) {
				if(a[x][y] == 'c') c++;
				if(a[x][y] == 'f') f++;
				dfs(x,y);	
			} 
		} 
	}
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int chicken = 0, fox = 0;
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m ;j++) {
 			cin >> a[i][j];	
 			if (a[i][j] == 'c') chicken++;
 			if (a[i][j] == 'f') fox++;
 			
 		} 	
 	} 
 	// cout << chicken << ' ' << fox <<endl;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m ;j++) {
 			if (vs[i][j] == 0 && a[i][j] != '#') {
 				if(a[i][j] == 'c') c++;
				if(a[i][j] == 'f') f++;

 				dfs(i,j);
 				if (f >= c) chicken -= c;
 				else fox -= f;
 				// cout << i << ' ' << j << ' ' <<endl;
 				// cout << "chicken:  " << c<< "   " << "fox:  " << f <<endl;
 				// cout << chicken << " " << fox <<endl << endl;
 				f = 0;
 				c = 0;

 			}
 		}	
 	} 

 	cout << fox << ' ' << chicken<<endl;

    return 0; 
}