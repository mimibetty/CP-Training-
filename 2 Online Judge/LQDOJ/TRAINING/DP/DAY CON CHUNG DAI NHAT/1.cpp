#include<bits/stdc++.h>
using namespace std;

int m,n;
int a[100005];
int b[100005];
int lcs[3005][3005];

int dp (int l, int r) {
    if (lcs[l][r] != -1) return lcs[l][r];
    if (l == 0 || r == 0) return 0;
    if (a[l] == b[r]) {
        lcs[l][r] = dp(l-1, r-1) + 1;
        return lcs[l][r];  
    }

    return lcs[l][r] = max(dp(l-1, r), dp(l, r-1) );
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(lcs, -1 ,sizeof(lcs) );
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    cout << dp(n,m);

    return 0;
}