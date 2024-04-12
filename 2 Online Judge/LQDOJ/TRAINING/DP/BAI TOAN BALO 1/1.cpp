#include<bits/stdc++.h>
using namespace std;

int a[105],b[105];
long long d[105][100005];

long long dp(int l, int r) {
    if (d[l][r] != -1) return d[l][r];

    if (l == 0) return 0;
    if (r == 0) return d[l][r];

    if (r - a[l] >= 0 ) return d[l][r] = max(dp(l-1, r - a[l]) + b[l], dp(l-1, r));
    else return d[l][r] = dp(l-1, r);
    }

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(d, -1 , sizeof(d));
    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    cout << dp(n,m);
    return 0;
}