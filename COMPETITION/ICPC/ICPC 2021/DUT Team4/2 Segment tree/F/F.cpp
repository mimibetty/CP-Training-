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
		long long val = 0;
		int h = 0;
	};

	vector<Node> st;
	int n;
	SegmentTree(int n) {
		st.resize(4 * n + 1);
	}

	void merge(Node &a, Node &b, Node &c) {
		a.h = b.h + 1;

 		if (a.h % 2 == 1) {
			a.val = b.val | c.val;
		}
		else {
			a.val = b.val ^ c.val;
		}
	}

	void build(vector<int> &a, int id, int l, int r) {
		if (l == r) {
			st[id].val = a[l];
			st[id].h = 0;
			return;
		}

		int mid = (l + r) / 2;
		build(a, id * 2, l, mid);
		build(a, id * 2 + 1, mid + 1, r);
		merge(st[id], st[id * 2], st[id * 2 + 1]);
	}

	void update(int id, int l, int r, int u, int v) {
		if (l == r) {
			st[id].val = v;
			return;
		}

		int mid = (l + r) / 2;
		if (u <= mid) update(id * 2, l, mid, u, v);
		else update(id * 2 + 1, mid + 1, r, u, v);
		merge(st[id], st[id * 2], st[id * 2 + 1]);
	}
};


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;

    n = (1 << n);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    SegmentTree seg(n);
    seg.build(a, 1, 1, n);

    for (int z = 1; z <= q; z++) {
    	int i, x;
    	cin >> i >> x;
    	seg.update(1, 1, n, i, x);

    	cout << seg.st[1].val << "\n";
    }

    return 0;
}