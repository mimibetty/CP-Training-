#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long a[105];
int pt5[105];
int pt2[105];
int d[105][105][3005];

int dp(int  vt, int k, int b5) {  // dp = max(b2)
    int res = -1e9;

    if (b5 < 0 || k < 0 || vt < 0) return -1e9;
    if (vt == 0) {
        //cout << vt << ' ' << k << ' ' << b5 << ' ' << res << endl; 
        if (k == 0 && b5 == 0) return 0;
        else return -1e9;
    }
    if (d[vt][k][b5] != -1) return d[vt][k][b5];

    
    res = max(res, dp(vt-1, k-1, b5 - pt5[vt]) + pt2[vt]);
    res = max(res, dp(vt-1, k, b5));
    //cout << vt << ' ' << k << ' ' << b5 << ' ' << res << endl; 
    return d[vt][k][b5] = res;
}
 //dp(vt,k, b5) = dp(vt - 1, k - 1, b5 - pt5[vt]) + pt2[vt] ,  dp(vt-1, k, b5)
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,k;
    int res = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        long long copy = a[i];
        while (copy % 5 == 0) {
            pt5[i]++;
            copy /= 5;
        }
        while (copy % 2 == 0) {
            pt2[i]++;
            copy /= 2;
        }
    }
    memset(d, -1, sizeof(d));
    
    for (int b5 = 0; b5 <= 3000; b5++) {
        int b2 = dp(n, k, b5);
        res = max(res, min(b2,b5));
    }
    cout << res;
    return 0;
}