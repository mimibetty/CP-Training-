/*
link submit: 
Note: 
tìm tổng các số có giá trị > median, gọi tổng là sumr, và có r số có giá trị > median => numr = sumr - median*r;
tìm tổng các số có giá trị < median, gọi tổng là suml, và có l số có giá trị < median => numl = suml - median*l;
res = numl + numr;

*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
const int NN = 200000;
int a[NN + 5];
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;

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
 
    void update(int id, int l, int r, int u, int v) {
        if (l == r) {
            st[id].cnt += v;
            return;
        }
 
        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, v);
        else update(id * 2 + 1, mid + 1, r, u, v);
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
 

void solve() {
    long long res = 0;
    int n,k;
    cin >> n >> k;
    Compressor<int>comp;
    SegmentTree st(NN + 5);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        comp.add(a[i]);
    }
    comp.compress();
    int vt = 1;
    IndexTree s; 
    ll sum = 0;
    for (int i = 1; i <= k; i++) {
        s.insert({a[i], i});
        st.update(1, 1, NN, comp.find(a[i]), a[i]);
    }
    auto mid = *s.find_by_order(k/2);
    int Comp_mid = comp.find(mid.fi);

    long long numleft = s.order_of_key({mid.fi,0});  
    long long numlright =  k - s.order_of_key({mid.fi,1e9}); 
    
    ll s2 =st.query(1,1,NN,Comp_mid + 1, NN).cnt - numlright * mid.fi;
    ll s1 = -st.query(1,1,NN,1, Comp_mid-1).cnt + numleft * mid.fi;
    
    res = s1 + s2;
    cout <<res<< " "; 
    
    for (int i = k + 1; i <= n; i++) {
        st.update(1,1,NN, comp.find(a[vt]), -a[vt]);
        s.erase(s.find({a[vt], vt}));

        s.insert({a[i], i});
        st.update(1, 1, NN, comp.find(a[i]), a[i]);
            

        mid = *s.find_by_order(k/2);
        Comp_mid = comp.find(mid.fi);

        numleft = s.order_of_key({mid.fi,0}); 
        numlright =  k - s.order_of_key({mid.fi,1e9}); 
        
        s2 =st.query(1,1,NN,Comp_mid + 1, NN).cnt - numlright * mid.fi;
        s1 = -st.query(1,1,NN,1, Comp_mid-1).cnt + numleft * mid.fi;
        

        res = s1 + s2;
        cout <<res<< " ";

        vt++;
    }



}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}