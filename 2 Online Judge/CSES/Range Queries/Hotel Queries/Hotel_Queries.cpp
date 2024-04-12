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
        long long maxx = 0;
    };

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.maxx = max(b.maxx, c.maxx);
    }

    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            st[id].maxx = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int val ) {
        if (l == r) {
            st[id].maxx = val;
            return;
        }

        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, val);
        else update(id * 2 + 1, mid + 1, r, u, val);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    int MaxLeast(int id, int l, int r, long long k) {
        // cout << id << ' ' << l << ' ' << r << ' ' << k << endl;
        if (l == r) return l;
        ll mid = (l + r) / 2;
        long long mx = st[id * 2].maxx; // so luong 1 trong (l,mid) 
        if (mx >= k) {
            // cout << "L  " <<"num  " <<  num << ' ' <<"mid  " <<  mid <<  endl;
            return MaxLeast(id * 2, l, mid, k);  
        } 
        else {
          // cout << "R  " <<"num  " <<  num << ' ' <<"mid  " <<  mid <<  endl;
              return MaxLeast(id * 2 + 1, mid + 1, r, k);
        }
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
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1);
    vector<int> ask(q + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> ask[i];
    }
    
    SegmentTree st(n);
    st.build(a, 1, 1, n);

    for (int i = 1; i <= q; i++) {

        int result = st.MaxLeast(1,1,n,ask[i]); 
        if (result == n && ask[i] > st.st[1].maxx) result = -1;
        
        if (result != -1) {
            a[result] -= ask[i];
            st.update(1, 1, n , result , a[result]);
            // result++;
        }
        else result++;
        cout << result << ' ';
    
    }

    return 0;
}
