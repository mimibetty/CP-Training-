#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int h[1005], s[1005];
int d[1005][100005];

int n,x;

int dp(int vt, int tien) {
    int res = -1e9;

    if (vt < 0 || tien < 0) return -1e9;
    if (tien == 0 && vt > 0) return 0;
    if (vt == 0) {
        //cout << vt << ' ' << tien << ' ' << res << endl;
        if (tien == 0) return 0;
        else return -1e9;
    }
    if (d[vt][tien] != -1) return d[vt][tien];

    res = max(res, dp(vt-1, tien - h[vt]) + s[vt]);
    res = max(res, dp(vt-1, tien));
    //cout << vt << ' ' << tien << ' ' << res << endl;
    return d[vt][tien] = res;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int res = -1e9;
    cin >> n >> x ;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int tien = 0; tien <= x; tien++) {
        res = max(res, dp(n,tien));
    }
    
    cout << res;
    return 0;

}