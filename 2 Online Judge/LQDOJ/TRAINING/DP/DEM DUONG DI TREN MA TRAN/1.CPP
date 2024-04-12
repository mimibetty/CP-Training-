#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
int n,m;
char a[1005][1005];
long long d[1005][1005];
bool isvalid(int w, int h) {
    if ( ((w > 0 && w <= m) || (h > 0 && h <= n)) && a[w][h] == '.') return 1;
    else return 0;
}

long long dp(int l,int r) {
    if (d[l][r] != -1) return d[l][r];
    if (isvalid(l,r) == 0 ) return 0;

    if (l == 1 && r == 1) return 1;

    d[l][r] = dp(l-1,r)% MOD + dp(l,r-1)%MOD;
    return d[l][r] %MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(d, -1, sizeof(d));
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }    

    cout << dp(n,m);
    return 0;
}