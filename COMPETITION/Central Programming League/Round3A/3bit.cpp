#include<bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> fen;
    int n;
    BIT(int n): n(n) {
        fen.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fen[i] = -1e9;
        }
    }
    void update(int u, int v) {
        for (int i = u; i <= n; i += i & -i) {
            fen[i] = max(fen[i], v);
        }
    }
    
    int getMax(int u) {
        if (u < 0 || u > n) return -1e9;

        int res = -1e9;
        for (int i = u; i; i -= i & -i) {
            res = max(res, fen[i]);
        }
        return res;
    }
};

int a[1505][1505];
int dp[1505][1505];
array<int, 3> b[2250005];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }    
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    vector<BIT> bitRow(n + 1, BIT(n));
    vector<BIT> bitRowSuf(n + 1, BIT(n));
    vector<BIT> bitCol(n + 1, BIT(n));
    vector<BIT> bitColSuf(n + 1, BIT(n));

    int idx = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[++idx] = {a[i][j], i, j};
            dp[i][j] = -1e9;
        }
    }

    sort(b + 1, b + n * n + 1);

    dp[x][y] = 1;
    bitRow[x].update(y, dp[x][y]);
    bitRowSuf[x].update(n - y + 1, dp[x][y]);
    bitCol[y].update(x, dp[x][y]);
    bitColSuf[y].update(n - x + 1, dp[x][y]);

    vector<pair<int, int>> temp;
    for (int t = 1; t <= n * n; t++) {
        // i - 1, i + 1, j - 1, j + 1
        // j - 2, j + 2, i - 2, i + 2
        auto [val, i, j] = b[t];

        if (i - 1 >= 1) {
            int maxDp = bitRow[i - 1].getMax(j - 2);
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = bitRowSuf[i - 1].getMax(n - j - 1);
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }
        
        if (i + 1 <= n) {
            int maxDp = bitRow[i + 1].getMax(j - 2);
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = bitRowSuf[i + 1].getMax(n - j - 1);
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }

        if (j - 1 >= 1) {
            int maxDp = bitCol[j - 1].getMax(i - 2);
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = bitColSuf[j - 1].getMax(n - i - 1);
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }

        if (j + 1 <= n) {
            int maxDp = bitCol[j + 1].getMax(i - 2);
            dp[i][j] = max(dp[i][j], maxDp + 1);

            maxDp = bitColSuf[j + 1].getMax(n - i - 1);
            dp[i][j] = max(dp[i][j], maxDp + 1);
        }

        // cout << dp[i][j] << endl;
        temp.push_back({i, j});
        if (b[t + 1][0] != b[t][0]) {
            for (auto [u, v]: temp) {
                bitRow[u].update(v, dp[u][v]);
                bitRowSuf[u].update(n - v + 1, dp[u][v]);
                bitCol[v].update(u, dp[u][v]);
                bitColSuf[v].update(n - u + 1, dp[u][v]);
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