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
 
#define fi first 
#define se second
#define pb push_back
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}


struct SegmentTree {
    struct Node {
        long long sum_odd = 0;
        long long sum_even = 0;
    };

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.sum_odd = (b.sum_odd + c.sum_odd);
        a.sum_even = (b.sum_even + c.sum_even);
    }

    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            if (l % 2 == 0) {
                st[id].sum_even = a[l];
                st[id].sum_odd = 0;
            }      
            else {
                st[id].sum_even = 0;
                st[id].sum_odd = a[l];
            }      
            return;
        }

        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, ll val) {
        if (l == r) {
            if (l % 2 == 0) {
                st[id].sum_even = val;
                st[id].sum_odd = 0;
            }      
            else {
                st[id].sum_even = 0;
                st[id].sum_odd = val;
            }
            return;
        }

        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, val);
        else update(id * 2 + 1, mid + 1, r, u, val);
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


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }    
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int>a(n+1);
    SegmentTree st(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st.build(a,1,1,n);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int u;
            ll val;
            cin >> u >> val;
            st.update(1,1,n,u,val);
        }
        else {
            int l,r;
            cin >> l >> r;
            ll val = st.query(1,1,n,l,r).sum_odd - st.query(1,1,n,l,r).sum_even;
            if (l % 2 == 0) val *= -1;
            cout << val << endl;
        }
    }

    
    return 0;
}
