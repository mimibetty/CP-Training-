#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

int n,m;
const long long  Mod = 1e9 + 7;
char a[1005][1005];
long long d[1005][1005];
bool check[1005][1005];

bool Isvalid(int l, int r) {
    if (l >= 1 && l <= n && r >= 1 && r <= m) return 1;
    return 0;
}

long long dp(int l, int r) {
    if (Isvalid(l,r) == 1) {
        if (check[l][r] != 0) return d[l][r];
        else if (l == 1 && r == 1) return 1;
        else if (a[l][r] == '.') {
                check[l][r] = 1;
                d[l][r] = dp(l-1,r)% Mod + dp(l,r-1)%Mod;
                d[l][r] %= Mod;
                return d[l][r];
        }
        return 0;
    }
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

    cout << dp(n,m);
    return 0;
}