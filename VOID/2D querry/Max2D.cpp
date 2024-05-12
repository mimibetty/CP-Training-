#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300; // Giả sử kích thước tối đa của ma trận
const int LOG = 9; // log2(MAXN)
int st[MAXN][MAXN][LOG][LOG];
int a[MAXN][MAXN];


int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    int n, m; // Kích thước của ma trận
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    // Xây dựng Sparse Table
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            st[i][j][0][0] = a[i][j];
    
    for (int lenx = 0; (1 << lenx) <= n; lenx++) {
        for (int leny = 0; (1 << leny) <= m; leny++) {
            if (lenx == 0 && leny == 0) continue;
            for (int x = 0; x + (1 << lenx) - 1 < n; x++) {
                for (int y = 0; y + (1 << leny) - 1 < m; y++) {
                    if (lenx > 0) {
                        st[x][y][lenx][leny] = max(st[x][y][lenx-1][leny], st[x + (1 << (lenx-1))][y][lenx-1][leny]);
                    } 
                    if (leny > 0) {
                        st[x][y][lenx][leny] = max(st[x][y][lenx][leny-1], st[x][y + (1 << (leny-1))][lenx][leny-1]);
                    }
                }
            }
        }
    }
    
    int q; // Số lượng truy vấn
    cin >> q;
    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        // i--; j--; // Đưa chỉ số về 0-based nếu đầu vào là 1-based
        int lenx = log2(k+1);
        int leny = log2(k+1);
        int max_val = max(max(st[i][j][lenx][leny], st[i + k - (1 << lenx) + 1][j][lenx][leny]), 
                        max(st[i][j + k - (1 << leny) + 1][lenx][leny], st[i + k - (1 << lenx) + 1][j + k - (1 << leny) + 1][lenx][leny]));
        cout << max_val << endl;
    }

    return 0;
}