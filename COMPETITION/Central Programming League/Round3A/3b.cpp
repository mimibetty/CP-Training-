#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        int max = -1e9;    
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

    void update(int id, int l, int r, int u, int val) {
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
        if (v < l || r < u || r < l) return Node();
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

int a[1505][1505];
int dp[1505][1505];
array<int, 3> b[2250005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    int idx = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[++idx] = {a[i][j], i, j};
            dp[i][j] = -1e9;
        }
    }

    sort(b + 1, b + n * n + 1);

    vector<SegmentTree> segRow(n + 1, SegmentTree(n));
    vector<SegmentTree> segCol(n + 1, SegmentTree(n));

    dp[x][y] = 1;
    segRow[x].update(1, 1, n, y, dp[x][y]);
    segCol[y].update(1, 1, n, x, dp[x][y]);

    vector<pair<int, int>> temp;
    for (int t = 1; t <= n * n; t++) {
        // i - 1, i + 1, j - 1, j + 1
        // j - 2, j + 2, i - 2, i + 2
        auto [val, i, j] = b[t];

        if (i - 1 >= 1) {
            int maxDp = segRow[i - 1].query(1, 1, n, 1, j - 2).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = segRow[i - 1].query(1, 1, n, j + 2, n).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }
        
        if (i + 1 <= n) {
            int maxDp = segRow[i + 1].query(1, 1, n, 1, j - 2).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = segRow[i + 1].query(1, 1, n, j + 2, n).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }

        if (j - 1 >= 1) {
            int maxDp = segCol[j - 1].query(1, 1, n, 1, i - 2).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = segCol[j - 1].query(1, 1, n, i + 2, n).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }

        if (j + 1 <= n) {
            int maxDp = segCol[j + 1].query(1, 1, n, 1, i - 2).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = segCol[j + 1].query(1, 1, n, i + 2, n).max;
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }

        // cout << dp[i][j] << endl;
        temp.push_back({i, j});
        if (b[t + 1][0] != b[t][0]) {
            for (auto [u, v]: temp) {
                segRow[u].update(1, 1, n, v, dp[u][v]);
                segCol[v].update(1, 1, n, u, dp[u][v]);
            }
            temp.clear();
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << dp[i][j] << ' ';
            res = max(res, dp[i][j]);
        }
        // cout << endl;
    }
    cout << res;

    return 0;
}