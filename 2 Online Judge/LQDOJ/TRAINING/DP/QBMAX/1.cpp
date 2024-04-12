#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105][105];
int d[105][105];
bool vs[105][105];

bool is_valid(int l, int r) {
    if (l > 0 && l <= n && r > 0 && r <= m) return 1;
    else return 0;
}

int dp(int l, int r) {
    if (vs[l][r] == 1) return d[l][r];
    vs[l][r] = 1;

    if (r == 1) {
        return d[l][r] = a[l][r];
    }

    for (int i = 0; i <= 2; i++) {
        if (is_valid(l+i-1, r-1) == 1) d[l][r] = max(d[l][r], dp(l + i - 1,r - 1) + a[l][r]);
    }
    return d[l][r];
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = -1e9;
        }
    }   

    int res = -1e9;
    for (int i = 1; i <= n; i++) {
        res = max(res,dp(i,m) );
       // cout <<i << ' '<< dp(i,m) << endl;
    }
    cout << res;
    return 0;
}