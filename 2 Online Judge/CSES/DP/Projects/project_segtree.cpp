#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;

// note dp[r] =max( p + max (dp[1] - > dp[l-1])   , max (dp[1] - > dp[r]) )
struct datas {
    int l, r;
    long long p;
    // Định nghĩa toán tử < để sắp xếp theo thứ tự ưu tiên l, sau đó đến r, và cuối cùng là p
    bool operator<(const datas& other) const {
        if (r != other.r)
            return r < other.r;
        return l < other.l;
    }
};

int n;
datas a[200005];

struct SegmentTree {
    struct Node {
        long long max = 0;
    }; 

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.max = max(b.max, c.max);
    }

    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            st[id].max = a[l];            
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, long long val) {
        if (l == r) {
            st[id].max = val; // or st[id].sum += val
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

void compress() {
    map<int,int>d; 
    for (int i = 1; i <= n; i++) {
        d[a[i].l]++;
        d[a[i].r]++;
    }

    int cnt = 0;
    map<int,int>convert;
    for(auto [key, val] : d) {
        cnt++;
        convert[key] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        a[i].l = convert[a[i].l];
        a[i].r = convert[a[i].r];
    }
}



int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long res = 0;
    int lenn;
    
    cin >> n;
    lenn = 2*n + 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].p;
    }

    compress();
    sort(a + 1, a + 1 + n);
    
    SegmentTree seg(lenn);
    for (int i = 1; i <= n; i++) {
        a[i].l++;
        a[i].r++;
    }


    for (int i = 1; i <= n; i++) {
        int l = a[i].l, r = a[i].r;
        
        // for (int j = 0; j <= r; j++) {
        //     dp[r] = max(dp[r], dp[j]);
        // }
        long long tmp1 = seg.query(1,1,lenn, 1, r).max;

        // for (int j = 0; j <= l - 1 ; j++) {
        //     dp[r] = max(dp[r], dp[j] + a[i].p);
        // }
        long long tmp2 = seg.query(1,1,lenn, 1, l-1).max + a[i].p;


        long long dpr = max(tmp1, tmp2);
        seg.update(1,1,lenn, r, dpr);
        res = max(res, dpr);
    }

    cout << res << endl;
    return 0;
}