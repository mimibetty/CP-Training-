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
        int cnt = 0;
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
            st[id].cnt = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update_Des(int id, int l, int r, int u) {
        if (l == r) {
            st[id].cnt--;
            return;
        }

        int mid = (l + r) / 2;
        if (u <= mid) update_Des(id * 2, l, mid, u);
        else update_Des(id * 2 + 1, mid + 1, r, u);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update_Inc(int id, int l, int r, int u) {
        if (l == r) {
            st[id].cnt++;
            return;
        }

        int mid = (l + r) / 2;
        if (u <= mid) update_Inc(id * 2, l, mid, u);
        else update_Inc(id * 2 + 1, mid + 1, r, u);
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
        
struct Query {  
    char type;
    int u,v;
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
int main() {

    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    int lenn = n + 2*q + 2;

    vector<Query>ff;
    vector<int> a(n + 1);
    Compressor<int>comp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        comp.add(a[i]);
    }

    SegmentTree st(lenn + 3);

    for (int i = 1; i <= q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k,x;
            cin >> k >> x;
            ff.pb({type,k,x});
            comp.add(x);
        }
        else {
            int l,r;
            cin >> l >> r;
            ff.pb({type,l,r});
            comp.add(l);
            comp.add(r);
        }
    }

    comp.compress();
    for (int i = 1; i <= n; i++) {
        a[i] = comp.find(a[i]);
    }

    for (int i = 0; i < ff.size(); i++) {
        if (ff[i].type == '!') {
            ff[i].v = comp.find(ff[i].v);
        }
        else {
            ff[i].u = comp.find(ff[i].u);
            ff[i].v = comp.find(ff[i].v);
        }
    }
    
    
    // for (auto i : a) cout << i << ' ';
    //     cout << endl;
    // for (auto i : ff) {
    //     if (i.type == '!') {
    //         cout << i.type << ' ' << i.v << endl;
    //     } 
    //     else cout << i.type << ' ' << i.u << ' ' << i.v << endl;
    // }
    // cout << endl;
    
    for (int i = 1; i <= n; i++) {
        st.update_Inc(1,1,lenn,a[i]);
    }
    for (auto i : ff) {
        if (i.type == '!') {
            st.update_Des(1,1, lenn, a[i.u]);
            a[i.u] = i.v;
            st.update_Inc(1,1, lenn, a[i.u]);            
        }
        else {
            int x = st.query(1,1,lenn, i.u, i.v).cnt;
            cout << x << endl;
        }
    }    
    return 0;
}
