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

struct SegmentTree {
	struct Node {
		int bit = 0;
	};

	vector<Node>st;
	SegmentTree(int n) {
		st.resize(4 * n);
	}

	void update(int id, int l, int r, int vt, int val) {
		// cout << id << ' ' << l << ' ' << r << ' ' << val <<  endl;
		if (l == r) {
			st[id].bit = val;
			return;
 		}

 		int mid = (l + r) /2;
 		if (vt <= mid) {
 			update(id * 2, l, mid, vt, val);
 		}
 		else {
 			update(id * 2 + 1, mid + 1, r, vt, val);
 		}

 		st[id].bit = st[id * 2].bit ^ st[id * 2 + 1].bit;
 		return;
 	}

	long long getXor(int id, int l, int r, int u, int v) {
		if (u <= l && v >= r) {
			return st[id].bit;
		}

		if (u > r || v < l) return 0;

		int mid = (l + r) / 2;
		return getXor(id * 2, l, mid, u, v) ^ getXor(id * 2 + 1, mid + 1, r, u , v);

	}
};

int main() {
	// freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
		
	int n,t;
	cin >> n >> t;
	SegmentTree st(n);
	vector<int>a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st.update(1, 1, n, i, a[i]);
	} 	

	// cout << 100 << endl;
	for (int z = 1; z <= t; z++) {
		int l,r;
		cin >> l >> r;

		// long long res = 0;
		// for (int i = l; i <= r; i++) {
		// 	res = res ^ a[i];
		// }
		// cout << res << endl;
		cout << st.getXor(1, 1, n, l, r) << endl;
	}
	return 0;
}