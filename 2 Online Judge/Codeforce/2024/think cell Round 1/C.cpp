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

    int n;
 
int a[300005];
struct SegmentTree {
    struct Node {
        long long maxx = -1e9;
        long long lazy = 0; // -1 nếu update là phép gán
    };
 
    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }
 
    void merge(Node& a, Node& b, Node& c) {
        a.maxx = max(b.maxx , c.maxx);    
    }
 
    void build(int id, int l, int r) {
        if (l == r) {
            st[id].maxx = a[l];
            return;
        }
 
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
 
    void down(int id, int l, int r) {
        if (l == r || st[id].lazy == 0) return;
 
        long long val = st[id].lazy;
 
        int mid = (l + r) / 2;
        st[id * 2].maxx += val;
        st[id * 2 + 1].maxx += val;
        
        st[id * 2].lazy += val;
        st[id * 2 + 1].lazy += val;
 
        st[id].lazy = 0;
    }
 
    void update(int id, int l, int r, int u, int v, long long val) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            st[id].maxx += val;
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
// int okk(int mid) {
//     return x;
// }
void solve() {
    cin >> n;
     SegmentTree st(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += i;
    }
    st.build(1,1,n);

    // for (int i = 1; i <= n; i++) {
    //     cout << st.query(1,1,n,i,i).maxx << ' ';
    // }
    EL;
    for (int i = 1; i <= n; i++) {
      int maxxx = st.query(1,1,n,1,n).maxx;
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        int xxx = st.query(1,1,n,1,mid).maxx ;

        if (xxx >= maxxx) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    // cout << l <<' ' << r <<  endl;
    }
    int    vt = l;

         // vt =       tim vi tri lon nhat cua s   
        // cout <<vt << ' ' << st.query(1,1,n,vt,vt).maxx << endl;
        cout << st.query(1,1,n,vt,vt).maxx << " ";
        
        st.update(1,1,n,vt,vt, -1e9);
        st.update(1,1,n,vt+1,n, -1);
    
    }
    cout << endl;

}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}