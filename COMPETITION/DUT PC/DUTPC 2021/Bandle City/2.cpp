#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

int n,m;
const long long Mod = 1e9 + 7;
char a[1005][1005];
long long d[1005][1005];

bool Isvalid(int l, int r) {
    if (l >= 1 && l <= n && r >= 1 && r <= m) return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    d[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') d[i][j] = 0;
            else {
                if (Isvalid(i-1, j) == 1) d[i][j] += d[i-1][j] % Mod;
                d[i][j] %= Mod;
                if (Isvalid(i, j-1) == 1) d[i][j] += d[i][j-1] %Mod;
                d[i][j] %= Mod;
            }
        }
    }
    cout << d[n][m];
    return 0;
}