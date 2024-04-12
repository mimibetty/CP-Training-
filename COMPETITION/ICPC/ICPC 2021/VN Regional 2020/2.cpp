#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
 
struct inf{
	ld x,y;
};
inf ar[500];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		ld a,b,c1,c2;
 		cin >> a >> b >> c1 >> c2;

 		int n ;
 		cin >> n;
 		for (int i = 1; i <= n; i++) {
 			cin >> ar[i].x >> ar[i].y;
 		}

 		bool ok = 0;

 		for (int i = 1; i < n; i++) {
 			if (ok == 1) break;
 			for (int j = i + 1; j <= n; j++) {
  				long aa,bb;
 				ld y1 = ar[i].y * ar[j].x;
 				ld y2 = ar[j].y * ar[i].x;
 				// dth y =ax+ b
 				if ((ar[i].x - ar[j].x) == 0 || ar[i].x == 0) continue;
 				bb = 1.00000*(y1-y2)/(ar[i].x - ar[j].x);
 				aa = 1.00000*(ar[i].y - bb)/ar[i].x;

 				// giao diem
 				long double xxx,yyy; 				
 				long double ax,bx,cx;
 				// dt1
 				if (b == 0) continue;
 				ax = -1.00000*a/b;
 				bx = 1.00000*c1/b;


 				if (aa == 0 || (ax - aa) == 0) continue;
 				yyy = 1.0000*(ax*bb -aa*bx)/(ax-aa);
 				xxx = (yyy - bb)/aa;

 				if (xxx >= min(ar[i].x, ar[j].x) && xxx <= max(ar[i].x, ar[j].x) &&	yyy >= min(ar[i].y, ar[j].y) && yyy <= max(ar[i].y, ar[j].y)) ok = 1; 
 				

 				//dt2
 				ax = -1.00000*a/b;
 				bx = 1.00000*c2/b;

 				yyy = 1.0000*(ax*bb -aa*bx)/(ax-aa);
 				xxx = (yyy - bb)/aa;

 				if (xxx >= min(ar[i].x, ar[j].x) && xxx <= max(ar[i].x, ar[j].x) &&	yyy >= min(ar[i].y, ar[j].y) && yyy <= max(ar[i].y, ar[j].y)) ok = 1; 
 				if (ok == 1) break;
 			}
 		}
 		if (ok == 0) cout << "NO" << endl;
 		else cout << "YES" << endl;
 		// cout << ok << endl;
 	}
    return 0;
}