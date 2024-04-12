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
 
int trace[1000005];
long  cnt[1000005];

void sieve(int n) {
	for (int i = 2; i * i <= n ;i++) {
		if (trace[i] == 0) {
			for (int j = i * i; j <= n; j+= i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	}

	for (int i = 2; i <= n ;i++) if (!trace[i]) trace[i] = i;
}

struct SegmentTree {
    struct Node {
        long long sum = 0;    
    }; 
 
    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }
 
    void merge(Node& a, Node& b, Node& c) {
        a.sum = (b.sum + c.sum) % MOD;
    }
 
    void build(vector<long long>& a, int id, int l, int r) {
        if (l == r) {
            st[id].sum = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
 
    void update(int id, int l, int r, int u, long long val) {
        if (l == r) {
            st[id].sum = val;
            return;
        }
        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, val);
        else update(id * 2 + 1, mid + 1, r, u, val); 
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
 
    Node query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return Node();
        if (u <= l && r <= v) {
            return st[id];
        }
        int mid = (l + r) / 2;
        auto a = query(id * 2, l, mid, u, v);
        auto b = query(id * 2 + 1, mid + 1, r, u, v);
        Node res;
        merge(res, a, b);
        return res;
    }
};

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	sieve(1e6);

 	for (int i = 2; i <= 1e6; i++) {
 		int val = i;
 		long long count_div = 1;
 		while (val > 1) {
 			int d = 0;
 			int q = trace[val];
 			while (val % q == 0) {
 				d++;
 				val /= q;
 			} 
 			count_div *= (d+1);
 		}
 		cnt[i] = count_div;
 		// cout << i << ' '<<count_div<<endl;
 	}
 	cnt[1] = 1;
 	int n,t ;
 	// scanf("%d%d",&n,&t);
 	cin >> n >> t;
 	vector<ll>a(n+1);
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		// scanf("%d",&a[i]);
 	} 
 	SegmentTree seg(n);
    seg.build(a, 1, 1, n);
	set<ll>s; // vi tri.0

	for(int i = 1; i <= n; i++) {
		if (a[i] != 2 && a[i] != 1) s.insert(i);
	} 
	// cout << cnt[10];
 	while (t--) {
 		// bool loai;
 		// if (t < 3) break;
 		long long l,r;
 		int loai;
 		// scanf("%lld %lld %lld",&loai,&l,&r);
 		
 		cin >>loai >>l >> r ;
 		// cout << loai << ' ' << l << ' ' << r << endl;
 		if (loai == 2) {
 			// printf("%lld \n", seg.query(1, 1, n, l, r).sum );
 			cout << seg.query(1, 1, n, l, r).sum << '\n';	
 		} 
 		else {
 			
 			auto it = s.lower_bound(l);
 			vector<int>vt;
 			while(it != s.end()) {
 				if (*it > r) break;
 				auto aa = *it;
 				auto x = seg.query(1, 1, n, aa, aa).sum;
	    		seg.update(1, 1, n, aa, cnt[x]);
	    		if (cnt[x] == 1 || cnt[x] == 2) {
	    			vt.pb(aa);
	    		}	
	    		++it;	
 			}
 			for (auto i : vt) s.erase(s.find(i));
 		} 
 	}
    return 0;
}