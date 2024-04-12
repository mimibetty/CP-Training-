#include <bits/stdc++.h>
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

const  long long MOD = 1e9 + 7;

// ll getCount(ll d, ll n)
// {
 
//     ll no = n / d;
//     ll result = no;
 
//     // Consider all prime factors
//     // of no. and subtract their
//     // multiples from result
//     for (ll p = 2; p * p <= no; ++p) {
 
//         // Check if p is a prime factor
//         if (no % p == 0) {
 
//             // If yes, then update no
//             // and result
//             while (no % p == 0)
//                 no /= p;
//             result -= result / p;
//         }
//     }
 
//     // If no has a prime factor greater
//     // than sqrt(n) then at-most one such
//     // prime factor exists
//     if (no > 1)
//         result -= result / no;
 
//     // Return the result
//     return result;
// }
 
// // Finding GCD of pairs
// ll sumOfGCDofPairs(ll n)
// {
//     ll res = 0;
 
//     for (ll i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             // Calculate the divisors
//             ll d1 = i;
//             ll d2 = n / i;
 
//             // Return count of numbers
//             // from 1 to N with GCD d with N
//             res += d1 * getCount(d1, n);
//  			res %= MOD;
//             // Check if d1 and d2 are
//             // equal then skip this
//             if (d1 != d2)
//                 res += d2 * getCount(d2, n);
//             	res %= MOD;
//         }
//     }
 
//     return res%MOD;
// }


ll f[500005];
int trace[500005];
long long phi[500005];

void sieve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i *i; j <= n; j+=i) {
                if (trace[j] == 0) trace[j] = i;
            }
        }
    }

    for (int j = 2; j <= n; j++) if (trace[j] == 0) trace[j] = j;
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

 
int main()
{
	freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    sieve(500000);

    phi[1] = 1;
    for (int i = 2; i <= 500000; i++) {
        phi[i] = i;
        ll val = i;
        while (val > 1) {
            int p = trace[val];
            if (val % p == 0) {
                phi[i] -= phi[i]/p;
                while (val % p == 0) val /= p;
            }
        }
    }

    f[1] = 1;
    for (int i = 2; i <= 5e5; i++) {
        f[i] += phi[i];
        f[i] %= MOD;
        for (int j = i; j <= 5e5; j+=i) {
            f[j] += 1ll * i * phi[j/i];
            f[j] %= MOD;
        }
    }

    // for (int i = 1; i <= 10; i++) cout << i << ' ' << f[i] << endl; 
    

    int n;
    cin >> n;
    vector<long long>a(n+1);
    for (int i = 1; i <= n; ++i) {
    	int val;
        cin >> val;
    	a[i] = f[val];	
    } 

    SegmentTree seg(n);
    seg.build(a, 1, 1, n);
    
    int t;
    cin >> t;
    while (t--) {
    	char d;
    	cin >> d;
  
    	if (d == 'C') {
    		int l,r;
    		cin >> l >> r;
            cout << seg.query(1, 1, n, l, r).sum << '\n';
    		// printf("%lld\n", seg.query(1, 1, n, l, r).sum);
    	}
    	else {
    		int x,y;
    		// scanf("%d %d", &x, &y);
    		cin >> x >> y;
    		seg.update(1, 1, n, x, f[y]);		
    	}
    }

    return 0;
}