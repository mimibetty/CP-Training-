#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll BASE = 31;
ll pw[200001];

struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(const string &s) {
        n = s.size();
        tree.resize(4*n);
        build(1, 0, n-1, s);
    }

    void build(int node, int l, int r, const string &s) {
        if (l == r) {
            tree[node] = (s[l] - 'a' + 1);
            return;
        }
        int mid = (l + r)/2;
        build(node*2, l, mid, s);
        build(node*2+1, mid+1, r, s);
        tree[node] = (tree[node*2]*pw[r - mid]%MOD + tree[node*2+1])%MOD;
    }

    void update(int node, int l, int r, int pos, char val) {
        if (l == r) {
            tree[node] = (val - 'a' + 1);
            return;
        }
        int mid = (l + r)/2;
        if (pos <= mid)
            update(node*2, l, mid, pos, val);
        else
            update(node*2+1, mid+1, r, pos, val);
        tree[node] = (tree[node*2]*pw[r - mid]%MOD + tree[node*2+1])%MOD;
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

    // Wrapper function update
    void update(int pos, char val) {
        update(1, 0, n-1, pos, val);
    }

    // Wrapper function getHash
    ll getHash(int l, int r) {
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

    pw[0] = 1;
    for (int i = 1; i <= n; ++i)
        pw[i] = pw[i-1]*BASE%MOD;

    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    SegmentTree forward(s);
    SegmentTree backward(s_rev);

    while (m--) {
        int type, a, b;
        char c;
        cin >> type;
        if (type == 1) {
            cin >> a >> c;
            --a;
            forward.update(a, c);

            // update tương ứng chuỗi đảo ngược
            int rev_pos = n - 1 - a;
            backward.update(rev_pos, c);
        } else {
            cin >> a >> b;
            --a; --b;
            ll hashForward = forward.getHash(a, b);

            // tính vị trí tương ứng trên chuỗi đảo ngược
            int new_l = n - 1 - b;
            int new_r = n - 1 - a;
            ll hashBackward = backward.getHash(new_l, new_r);

            if (hashForward == hashBackward)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}


dp[i][j] so ruou uong toi vi tri i va co j thang lien tiep

tmp_ps[j]
dp[i][j] = dp[i-1][j-1] + a[i]
dp[i][0] = max dp[i-1],[j] (moij j )

dp[i] 
dp[i-1]

dp[i][1] = dp[i-1][0] + a[i]
dp[i][2] = dp[i-1][1] + a[i]
dp[i][k] = dp[i-1][k-1] + a[i]

maxVal = max()
max dp[n][j]