#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n, m;
ll res = 0;
const ll mod = 1e9 + 7;

ll a[105][105];

bool check(int i, int j) {
    if (i >= 3 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i-2][j]) return false;
    if (j >= 3 && a[i][j] == a[i][j-1] && a[i][j-1] == a[i][j-2]) return false;
    if (i >= 2 && j >= 2 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i][j-1]) return false;
    if (i >= 2 && j >= 2 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i-1][j-1]) return false;
    if (i >= 2 && j <= m - 1 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i-1][j+1]) return false;
    if (i >= 2 && j >= 2 && a[i][j] == a[i-1][j-1] && a[i-1][j-1] == a[i][j-1]) return false;
    return true;
}

void dequy(int i, int j) {
    if (i > n) {
        res = (res + 1) % mod;
        int den = 0, trang = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl; 
        }
        cout << endl;
        return;
    }
    if (j > m) {
        dequy(i + 1, 1);
        return;
    }
    
    a[i][j] = 1;
    if (check(i, j)) {
        dequy(i, j + 1);
    }
    
    a[i][j] = 0;
    if (check(i, j)) {
        dequy(i, j + 1);
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    dequy(1, 1);
    cout << res << endl;
}