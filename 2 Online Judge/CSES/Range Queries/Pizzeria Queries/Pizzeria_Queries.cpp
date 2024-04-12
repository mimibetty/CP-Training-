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


#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        long long min1 = 1e10;
        long long min2 = 1e10;    
    }; 

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.min1 = min(b.min1, c.min1);
        a.min2 = min(b.min2, c.min2);
    }

    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            st[id].min1 = a[l] + l;
            st[id].min2 = a[l] - l;
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int val) {
        if (l == r) {
            st[id].min1 = val + l;
            st[id].min2 = val - l;
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
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree st(n);
    st.build(a, 1, 1, n);

    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u,v;
            cin >> u >> v;
            st.update(1,1,n,u,v);
        }    
        else {
            int u;
            cin >> u;
            ll res = 1e10;
            if (u != 1) {
                res = min(res, st.query(1,1,n,1,u).min2 + u);
            }
            if (u != n) {
                res = min(res, st.query(1,1,n,u,n).min1 - u);
            }
            
            cout << res <<endl;
        }
    }
    return 0;
}