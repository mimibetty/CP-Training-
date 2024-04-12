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

int a[100005];


struct SegmentTree {
    struct Node {
        int max = -1e9;    
        int min = 1e9;    

    }; 

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.max = max(b.max, c.max);
           a.min = min(b.min, c.min);
    
    }

    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            st[id].max = a[l];
            st[id].min = a[l];
            
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int val) {
        if (l == r) {
            st[id].max = val; // or st[id].sum += val
            st[id].min = val; // or st[id].sum += val
     
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


void solve() {
    int n;
    cin >> n;
    vector<int>a(n + 2);
    vector<int>ps(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }    
    int res = - 1e9;
    
    SegmentTree st(n + 3);
    st.build(a,1,1,n);

    ps[0] = 0;
    SegmentTree st2(n + 3);
    st2.build(ps,1,1,n);
    // cout << st2.query(1,1,n,0,0).max << endl; 
    for (int i = 1; i <= n; i++) {
        int l1,r1; 

        int l = 1, r = i;
        // tim ben trai 
        while (l < r) {
            int mid = (l + r ) / 2;
            if (st.query(1,1,n,mid,i).max == a[i]) {
                r = mid;
            }
            else l = mid + 1;
        }

        l1 = l;
        // cout << a[i] << ' ' << l << ' ' << a[l] << endl;
   

        l = i, r = n;
        // tim ben phai 
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (st.query(1,1,n,i,mid).max == a[i]) {
                l = mid;
            }
            else r = mid - 1;
        }

        r1 = l;
        int sr = st2.query(1,1,n,i,r1).max;
        int sl = st2.query(1,1,n,l1,i).min;
        if (l1 == 1) sl = min(sl, 0); 
        if (sr == sl) {
            res = max(res, 0 );
            continue;  
        } 
        res = max(res, sr - sl - a[i]);
        // cout <<a[i] << ' ' <<  sr - sl - a[i] << ' ' <<l1 << ' ' << r1 <<endl;
        // cout << sl << ' ' << sr << endl << endl;
        // res = max(res, st.query(1,1,n,i,r1). m)
    }
    cout << res << endl;


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
    while (t--)    
    solve();

    return 0;
}