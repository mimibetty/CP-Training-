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
 
int val[100005];
int color[100005];
vector<int>posOfColor[100005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,k;
 	cin >> n >> k;

 	for (int i = 1; i <= n; i++) {
 		cin >> val[i] >> color[i];
 		posOfColor[color[i]].pb(val[i]);
 	}

 	for (int i = 1; i <= k ; i++) {
 		sort(All(posOfColor[i]));
 	}
 	bool check = 1;
 	for (int i = 1; i <= n; i++) {
		auto q = lower_bound(posOfColor[color[i]].begin(), posOfColor[color[i]].end(), i) - posOfColor[color[i]].begin();
 		if (posOfColor[color[i]][q] != i) {
 			check = 0;
 			break;
 		}
 	}
 	if (check == 1) cout << "Y";
 	else cout << "N";
    return 0;
}