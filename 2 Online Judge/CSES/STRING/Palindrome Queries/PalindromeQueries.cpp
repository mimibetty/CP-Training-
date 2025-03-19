#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll BASE = 31; // base cho hash rolling
ll pw[200001]; // mảng lưu BASE^i % MOD

// Segment tree lưu hash
struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(const string &s, bool reverse) {
        n = s.size();
        tree.resize(4*n);
        build(1, 0, n-1, s, reverse);
    }

    void build(int node, int l, int r, const string &s, bool reverse) {
        if (l == r) {
            tree[node] = (s[reverse ? (n-1-l) : l] - 'a' + 1);
            return;
        }
        int mid = (l + r)/2;
        build(node*2, l, mid, s, reverse);
        build(node*2+1, mid+1, r, s, reverse);
        tree[node] = (tree[node*2]*pw[r-mid]%MOD + tree[node*2+1])%MOD;
    }

    void update(int node, int l, int r, int pos, char val, bool reverse) {
        if (l == r) {
            tree[node] = (val - 'a' + 1);
            return;
        }
        int mid = (l + r)/2;
        if (pos <= mid)
            update(node*2, l, mid, pos, val, reverse);
        else
            update(node*2+1, mid+1, r, pos, val, reverse);
        tree[node] = (tree[node*2]*pw[r-mid]%MOD + tree[node*2+1])%MOD;
    }

    ll getHash(int node, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r)/2;
        ll leftHash = getHash(node*2, l, mid, u, v);
        ll rightHash = getHash(node*2+1, mid+1, r, u, v);
        int rightLen = max(0, min(r, v) - mid);
        return (leftHash*pw[rightLen]%MOD + rightHash)%MOD;
    }

    void update(int pos, char val, bool reverse) {
        // ????
        update(1, 0, n-1, reverse ? (n-1-pos) : pos, val, reverse);
    }

    ll getHash(int l, int r, bool reverse) {
        if (reverse) {
            int new_l = n - 1 - r;
            int new_r = n - 1 - l;
            l = new_l; r = new_r;
        }
        return getHash(1, 0, n-1, l, r);
    }
};

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    // Tính trước powers của BASE
    pw[0] = 1;
    for (int i = 1; i <= n; ++i)
        pw[i] = pw[i-1]*BASE%MOD;

    SegmentTree forward(s, false);
    SegmentTree backward(s, true);

    while (m--) {
        int type, a, b;
        char c;
        cin >> type;
        if (type == 1) {
            cin >> a >> c;
            --a;
            forward.update(a, c, false);
            backward.update(a, c, true);
        } else {
            cin >> a >> b;
            --a; --b;
            ll hashForward = forward.getHash(a, b, false);
            ll hashBackward = backward.getHash(a, b, true);
            if (hashForward == hashBackward)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}