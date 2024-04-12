#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105][105];
long long d[105][105];

bool is_valid(int l, int r) {
    if (l > 0 && l <= n && r > 0 && r <= m) return 1;
    else return 0;
}

long long dp(int l, int r) {
    if (d[l][r] != -1e9) return d[l][r];
    if (l == 1) return d[l][r] = a[l][r];

    for (int i = 0; i <= 2; i++) {
        if (is_valid(l+i-1, r-1) == 1) d[l][r] = max(d[l][r], dp(l + i - 1,r-1) + a[l][r]);
    }
    return d[l][r];
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    cin >> n >>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = -1e9;
        }
    }   
    long long res = -1e18;
    for (int i = 1; i <= n; i++) {
        res = max(res,dp(i,m) );
       // cout <<i << ' '<< dp(i,m) << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << i <<' ' << j << ' ' dp(i,j) << endl;
        }
    }    
    //   cout << res;
    return 0;
}