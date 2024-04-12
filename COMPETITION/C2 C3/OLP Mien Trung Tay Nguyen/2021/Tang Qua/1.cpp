#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[4005];
bool check[4005][4005];
int d[4005][4005];

int dp(int l,int r) {
    if (check[l][r] != 0) return d[l][r];
    else if (l >= r) {
        check[l][r] = 1;
        return 0;
    }
    else if (abs(a[l] - a[r]) <= k ) {
        check[l][r] = 1;
        return d[l][r] = 1 + dp(l+1, r-1);
    }
    else {
        check[l][r] = 1;
        return d[l][r] = max(dp(l+1, r), dp(l, r-1) );
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(check, 0, sizeof(check));    
    cin >> n >> k;

    for (int i = 1; i <= 2*n; i++) {
        cin >> a[i];
    }
    cout << dp(1, 2*n);
    return 0;
}