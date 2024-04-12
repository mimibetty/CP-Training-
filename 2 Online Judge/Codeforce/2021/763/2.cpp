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
 
struct abc {
	int l,r,num;
};
bool cmp(abc a, abc b) {
	if (a.num == b.num) {
		if (a.l == b.l) {
			return a.r < a.r;
		}
		return a.l < b.l;
	}
	else return a.num < b.num;
}

abc a[1005];
abc b[1005];

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
 		vector<int>res(n+1);
 		vector<vector<int>>vt;
 		vt.assign(n+1, vector<int>(n+1));
 		for (int i = 1; i <= n; i++) {
 			int l,r;
 			cin >> l >> r;
 			a[i].l = l;
 			a[i].r = r;
 			a[i].num = r - l + 1;
 		 		// cout << 100 << endl;
 			vt[l][r] = i;

 			b[i].l = l;
 			b[i].r = r;
 		}
 		sort(a+1, a+1 + n, cmp);
 		// for (int i = 1;i <= n; i++) cout <<a[i].l << ' '<<a[i].r << endl;
 		set<int>s;
 		for (int i = 1; i <= n; i++) s.insert(i);

 		for (int i = 1; i <= n; i++) {
 			auto q1 = s.lower_bound(a[i].l);
 			auto q2 = s.upper_bound(a[i].r);
 			--q2;
 			// cout << i << ' '<< *q1 << ' '<<*q2 <<endl;
 			if (q1 == q2) {
 				res[ vt[a[i].l][a[i].r] ] = *q1;
 				s.erase(q1);
 			}
 		}
 		int check = 1;
 		while (check == 1) {
 			check = 0;
 			for (int i = 1; i <= n; i++) {
	 			if (res[ vt[a[i].l][a[i].r] ] != 0) continue;
	 			auto q1 = s.lower_bound(a[i].l);
	 			auto q2 = s.upper_bound(a[i].r);
	 			--q2;
	 			if (q1 == q2) {
	 				res[ vt[a[i].l][a[i].r] ] = *q1;
	 				s.erase(q1);
	 			}
	 			if (res[ vt[a[i].l][a[i].r] ] != 0) check = 1;
 			}	
 		}
 		// cout <<endl;
 		for (int i = 1; i <= n; i++) cout <<b[i].l << ' '<< b[i].r << ' '<< res[i] << endl;
 			cout <<endl;
 	}
    return 0;
}