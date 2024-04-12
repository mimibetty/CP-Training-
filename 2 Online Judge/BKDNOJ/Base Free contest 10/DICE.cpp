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
int cnt1[305], cnt2[305];
int ps1[305],ps2[305];
double epx = 1e-9;
void solve() {

 	for (int i = 1; i <= 4; i++) cin >> a[i];
 	for (int i = 1; i <= 4; i++) cin >> b[i];
 	int l1 = a[1] + a[3];
 	int r1 = a[3] + a[4];

 	int l2 = b[1] + b[3];
 	int r2 = b[3] + b[4];

 	for (int i = a[1]; i <= a[2]; i++) {
 		for (int j = a[3]; j <= a[4];j++) {
 			cnt1[i + j]++;
 		}
 	}
	
	for (int i = b[1]; i <= b[2]; i++) {
 		for (int j = b[3]; j <= b[4];j++) {
 			cnt2[i + j]++;
 		}
 	}
	
	for (int i = 1; i <= 300;i++) {
		ps1[i] = ps1[i-1] + cnt1[i];
		ps2[i] = ps2[i-1] + cnt2[i];
	}

	// precision(5);
	long double win1 = 0, win2 = 0;
	for (int i = 1; i <= 300; i++) {
		win1 += 1.0000*cnt1[i]*ps2[i-1] / (1.0000*(a[2] - a[1] + 1) * (b[4] - b[3] + 1) * (b[2] - b[1] + 1) * (a[4] - a[3] + 1) );
		win2 += 1.0000*cnt2[i]*ps1[i-1] / (1.0000*(a[2] - a[1] + 1) * (b[4] - b[3] + 1) * (b[2] - b[1] + 1) * (a[4] - a[3] + 1) );
	}
	// cout << win1 << ' ' << win2 << endl;
	
	if (abs(win1 - win2) <= epx) {
		cout << 3 << endl;
		return;
	}
	if (win1 > win2) cout << 1 << endl;
	else if(win2 > win1) {
		cout << 2 << endl;
	}
	else cout << 3;
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