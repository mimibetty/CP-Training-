#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        long long min = 1e18; // max = -1e18, min = 1e18;
        long long lazy = 0; // lazy = -1 neu la phep gan
    };

    vector<Node> st;
    int n;
    SegmentTree(int n): n(n) {
        st.resize(4 * n + 1);
    }

    void merge(Node& a, Node& b, Node& c) {
        a.min = min(b.min, c.min);
        // a.max = max(b.max, c.max)
    }

    void build(vector<long long> &a, int id, int l, int r) {
        if (l == r) {
            st[id].min = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void down(int id, int l, int r) {
        if (l == r || !st[id].lazy) return;
        // lazy != -1 neu la phep gan

        long long val = st[id].lazy;

        int mid = (l + r) / 2;
        st[id * 2].min += val;
        st[id * 2 + 1].min += val;

        st[id * 2].lazy += val;
        st[id * 2 + 1].lazy += val;

        st[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, long long val) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            st[id].min += val;
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
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(n);
    seg.build(a, 1, 1, n);

    int q;
    cin >> q;
    cin.ignore();

    for (int i = 1; i <= q; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);

        long long x;
        vector<long long> ope;
        while (ss >> x) {
            ope.push_back(x);
        }

        if (ope.size() == 2) {
            int l = ope[0] + 1;
            int r = ope[1] + 1;

            if (l <= r) cout << seg.query(1, 1, n, l, r).min << "\n";
            else {
                long long min1 = seg.query(1, 1, n, 1, r).min;
                long long min2 = seg.query(1, 1, n, l, n).min;
                cout << min(min1, min2) << "\n";
            }
        }
        else {
            int l = ope[0] + 1;
            int r = ope[1] + 1;

            if (l <= r) seg.update(1, 1, n, l, r, ope[2]);
            else {
                seg.update(1, 1, n, l, n, ope[2]);
                seg.update(1, 1, n, 1, r, ope[2]);
            }
        }
    } 

    return 0;
}
