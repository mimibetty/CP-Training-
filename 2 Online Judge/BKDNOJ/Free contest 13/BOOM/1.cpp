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
 
ll a[305][305];
	
int n;
bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}



int main() {

	if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    cin >> n;
    int t;
    cin >> t;


    while(t--) {
    	ll x,y,dame;
    	cin >> x >> y >> dame;
    	a[x][y] += dame;
    	int lx,ly,rx,ry;
    	lx = x; ly = y;
    	rx = x; ry = y;
    	
    	dame--;
    	lx--; ly--;
    	rx++; ry++;

    	while (dame > 0 ) {
    		for (int i = lx; i <= rx; i++) {
    			if(valid(i,ly) == 1) {
    				a[i][ly] += dame;
    			} 
    			if(valid(i,ry) == 1) {
    				a[i][ry] += dame;
    			}  
	    	}

    		for (int i = ly; i <= ry; i++) {
    			if(valid(lx,i) == 1) {
    				a[lx][i] += dame;
    			} 
    			if(valid(rx,i) == 1) {
    				a[rx][i] += dame;
    			}  
	    	}
	    	if (valid(lx,ly)) a[lx][ly] -= dame;
	    	if (valid(lx,ry)) a[lx][ry] -= dame;
	    	if (valid(rx,ly)) a[rx][ly] -= dame;
	    	if (valid(rx,ry)) a[rx][ry] -= dame;
			dame--;
	    	lx--; ly--;
	    	rx++; ry++;
    	}

    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		res = max(res, a[i][j]);
    		// cout << a[i][j] << ' ';
    	}
    	// cout << endl;
    }
    cout << res << endl;
    return 0;
}