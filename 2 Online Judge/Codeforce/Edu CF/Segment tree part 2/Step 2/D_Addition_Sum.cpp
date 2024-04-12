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
        long long sum = 0;
        long long lazy = 0; // -1 nếu update là phép gán
    };

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.sum = b.sum + c.sum;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id].sum = 0;
            return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void down(int id, int l, int r) {
        if (l == r || !st[id].lazy) return;

        long long val = st[id].lazy;

        int mid = (l + r) / 2;
        st[id * 2].sum += val * (mid - l + 1);
        st[id * 2 + 1].sum += val * (r - mid);

        st[id * 2].lazy += val;
        st[id * 2 + 1].lazy += val;

        st[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, long long val) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            st[id].sum += val * 1ll * (r - l + 1);
            st[id].lazy += val;
            return;
        } 

        down(id, l, r);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return Node();
        if (u <= l && r <= v) {
            return st[id];
        }

        down(id, l, r);
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
    
    int n,q;
    cin >> n >> q;
    SegmentTree st(n + 1);
    st.build(1,1,n);
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            ll l, r, val;
            cin >> l >> r >> val;
            l++;
            st.update(1,1,n,l,r,val);
        }
        else {
            int l,r;
            cin >> l >> r;
            l++;
            cout << st.query(1,1,n,l,r).sum << endl;
        }
    }    return 0;
}