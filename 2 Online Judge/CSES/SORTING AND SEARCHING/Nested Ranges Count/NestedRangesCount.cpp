/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}


struct SegmentTree {
    struct Node {
        long long cnt = 0;
    };

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.cnt = (b.cnt + c.cnt);
    }

    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            st[id].cnt = 1;
            return;
        }

        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u) {
        if (l == r) {
            st[id].cnt = 1;
            return;
        }

        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u);
        else update(id * 2 + 1, mid + 1, r, u);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return Node();
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


// Usage:
// Compressor<int> comp;
// Adding an element                : comp.add(value)
// After having all                 : comp.compress()
// Find index of value v            : comp.find(v) (1-based index)
// Get the original value of index i: comp.orig[i] (1-based index) 

template <class T>
struct Compressor {
    vector<T> values, orig;
    void add(T x) {
        values.push_back(x);
    }

    void compress() {
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        orig.resize(values.size() + 1);

        for (int i = 0; i < values.size(); i++) {
            orig[i + 1] = values[i];
        }
    }

    // return index of value: a[i] >= x (lower_bound)
    T find(T x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin() + 1;
    }

    // return max index: a[i] <= x
    T find2(T x) {
        return upper_bound(values.begin(), values.end(), x) - values.begin();
    }
};

int a[200005];
struct dataa {
    int l = 0;
    int r = 0;
    int val;
};

bool cmp(dataa &a, dataa &b) {
    return a.r < b.r;
}
dataa f[200005];
int res[200005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }    
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    Compressor <int> comp;

    SegmentTree st(2*n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        comp.add(x);
        comp.add(y);
        f[i].l = x;
        f[i].r = y;
        f[i].val = i;
    }
    comp.compress();
    for (int i = 1; i <= n; i++) {
        f[i].l = comp.find(f[i].l);
        f[i].r = comp.find(f[i].r);
    }

    sort(f+1, f+1+n,cmp);
    for (int i = 1; i <= n; i++) {
        cout << f[i].l << ' ' << f[i].r << endl;
    }
    EL;
    EL;
    for (int i = 1; i <= n; i++) {
        res[f[i].val] = st.query(1,1,2*n,f[i].l + 1, f[i].r).cnt;
        st.update(1,1,2*n,f[i].l);
        cout << f[i].val << ' ' << res[f[i].val] <<endl;
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    
    return 0;
}
