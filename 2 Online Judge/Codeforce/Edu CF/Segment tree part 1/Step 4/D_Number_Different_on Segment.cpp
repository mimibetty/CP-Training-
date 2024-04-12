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
        int cnt[41] = {0};
    };

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        for (int i = 1; i <= 40; i++) {
            a.cnt[i] = (b.cnt[i] + c.cnt[i]);
        }
    }
    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            st[id].cnt[a[l]] = 1;      
            return;
        }

        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int val, int Old_val ) {
        if (l == r) {
            st[id].cnt[Old_val]--;
            st[id].cnt[val]++;
            return;
        }

        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, val, Old_val);
        else update(id * 2 + 1, mid + 1, r, u, val, Old_val);
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
    
    int n,q ;
    cin >> n >> q;
    vector<int>a(n+1);
    SegmentTree st(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // st.update(1,1,n,i,a[i],0);
    }
    st.build(a,1,1,n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int u;
            ll val;
            cin >> u >> val;
            st.update(1,1,n,u,val, a[u]);
            a[u] = val;
        }
        else {
            int l,r;
            cin >> l >> r;
            int res = 0;
            auto ff = st.query(1,1,n,l,r);
            for (int i = 1; i <= 40; i++) {
                if(ff.cnt[i]) res++;
            }
            cout << res << endl;
        }
    }

    
    return 0;
}
