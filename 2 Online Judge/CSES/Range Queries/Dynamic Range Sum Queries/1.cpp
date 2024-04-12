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

const int maxN = 2e5 + 5;

struct SegmentTree{
	struct Node {
		// int max = 0;
		long long sum = 0;
		// int min = 1e9;
	};

	vector<Node>st;
	SegmentTree(int n) {
		st.resize(4 * n);
	}

	void update(int id, int l, int r, int vt, int val) {
		if (l == r) {
			st[id].sum = val;
			return;
		}

		int mid = (l + r) / 2;
		if (vt <= mid) {
			update(id * 2, l, mid, vt, val);
		}
		else {
			update(id * 2 + 1, mid + 1, r, vt , val);
		}

		st[id].sum = st[id*2].sum + st[id*2 + 1].sum; 
	}

	long long getSum(int id, int l, int r, int u, int v) {
		if (v < l || r < u) {
			return 0;
		}

		if (l >= u && r <= v) {
		// cout << id << ' ' << l << ' ' << r << ' '<< u <<  endl;
			return st[id].sum;
		}
		int mid = (l + r) / 2;
		return getSum(id*2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v); 
	}
};


int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int t,n;
	cin >> n >> t;
	vector<int>a(n+1);
	SegmentTree st(n);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st.update(1, 1, n, i, a[i]);	
	} 
	// for (int i = 0; i < n; i++) cout << st.getSum(1,0,n-1,i,i) << ' ';
	
	for (int z = 1; z <= t; z++) {
		int type_query;
		cin >> type_query;

		if (type_query == 1) {
			int ele, val;
			cin >> ele >> val;
			// for (int i = 0; i < n; i++) cout << st.getSum(1, 0, n-1, i, i) << ' ';
			st.update(1, 1, n, ele, val);
		}
		else {
			int l,r;
			cin >> l >> r;
			cout << st.getSum(1, 1, n, l, r) << endl;
		}
	} 

    return 0;
}