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
        long long sum = 4294967295;
    };
 
    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }
 
    void merge(Node& a, Node& b, Node& c) {
        a.sum = (b.sum & c.sum);
    }
 
    void build(vector<ll> &a, int id, int l, int r) {
        if (l == r) {
            st[id].sum = a[l];
            return;
        }
 
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }
 
    void update(int id, int l, int r, int u, int val) {
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
    int n;
    cin >> n;
    vector<ll>a(n+2);
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
    }

    SegmentTree st(n + 3);
    st.build(a,1,1,n);
    
    // for (int i = 1; i <= n ;i++) {
    //     cout << st.query(1,1,n,i,i).sum << ' ';
    // }
    // EL;
    
    // cout << st.query(1,1,n,1,2).sum << ' ' << st.query(1,1,n,1,3).sum << endl;
    ll x = a[1];
    
    for (int i = 1; i <= n; i++) {
        x &= a[i];
    }
    if (x > 0) {
        cout << 1 << endl;
        return;
    }
    // cout << x << endl;
    int cnt = 1;
    int end = 0;
    for (int i = 1; i < n; i++) {
        if (st.query(1,1,n,end + 1, i).sum == x && st.query(1,1,n,i + 1, n).sum == x) {
            cnt++;
            end = i;
         }
        // cout << i << ' ' << end << ' ' <<st.query(1,1,n,i + 1, n).sum << endl;
    }
    cout << cnt << endl;
    // cout << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    solve();
       
    return 0;
}