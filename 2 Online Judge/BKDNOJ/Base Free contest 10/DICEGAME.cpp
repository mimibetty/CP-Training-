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
 
int a[10],b[10];
void solve() {

 	for (int i = 1; i <= 4; i++) cin >> a[i];
 	for (int i = 1; i <= 4; i++) cin >> b[i];
 	int l1 = a[1] + a[3];
 	int r1 = a[3] + a[4];

 	int l2 = b[1] + b[3];
 	int r2 = b[3] + b[4];

	if(l1 == l2 && r1 == r2) {
		cout << 3 <<endl;
		return;
	} 	
	if (l1 >= l2 && r1 >= r2) {
		cout << 1 << endl;
		return;
	}
	if (l2 >= l2 && r2 >= r1) {
		cout << 2 << endl;
		return;
	}
	cout << 3 << endl;
	return;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	solve();
    return 0;
}