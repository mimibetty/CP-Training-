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

long long res[3];
 
struct SegmentTree {
    struct Node {
        long long sum = 0;//4294967295;
    };
 
    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }
 
    void merge(Node& a, Node& b, Node& c) {
        a.sum = (b.sum ^ c.sum);
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
    vector<long long>a(n+2);
    SegmentTree st(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st.build(a,1,1,n);
    
    string s ;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n;i++) {
        if (s[i] == '1') {
            res[1] ^= a[i];
        }
        else {
            res[0] ^= a[i];
        }
    }
    int t;
    cin >> t;
    
    for (int z = 1; z <= t; z++) {
        int q;
        cin >> q;
        if (q == 1) {
            int l,r;
            cin >> l >> r;
            // for (int i = l; i <= r ; i++) {
            //     res[1] ^= a[i];
            //     res[0] ^= a[i];
            // }
            res[1] ^=  st.query(1,1,n,l, r).sum;
            res[0] ^= st.query(1,1,n,l, r).sum;
        }
        else {
            int c;
            cin >> c;
            cout << res[c] << ' ';
            // cout << res[0] << ' ' << res[1] << endl;;
            // cout << res[c] << ' ' << res[1-c] << endl;;
               
        }
    }
    cout << endl;
    // cout << endl <<endl;
    res[1] = res[0] = 0;
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