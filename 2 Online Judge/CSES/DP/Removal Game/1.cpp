#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long a[5005];
bool check[5005][5005];
long long d[5005][5005];
long long dp(int l, int r) {
    if (check[l][r] != 0) return d[l][r];
    if (l == r) return a[l];
    if (l >= r) return 0;

    long long b = a[l] + min(dp(l+1, r-1), dp(l+2,r));
    long long c = a[r] + min(dp(l+1, r-1), dp(l, r-2));

    d[l][r] = max(b,c);
    check[l][r] = 1;
    return d[l][r];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(check, 0, sizeof(check));
    
    cout << dp(1,n);
    return 0;
}