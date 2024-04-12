#include <bits/stdc++.h>
using namespace std;

long long a[105];
int d[105][105][3005];
int pt2[105];
int pt5[105];

int dp(int vt, int k,int b5) {
    int res = -1e9;
    if (k < 0 || b5 < 0) return -1e9;
    if (vt == 0) {
        // cout << vt << ' ' << k << ' ' << ' '<< b5 << ' ' << res << ' '<< pt5[vt]<<  endl; 
        if (k == 0 && b5 == 0) return 0;
        else return -1e9;
    } 

    if (d[vt][k][b5] != -1) return d[vt][k][b5];

    res = max(res, dp(vt-1,k-1 , b5- pt5[vt]) + pt2[vt]);
    res = max(res, dp(vt-1, k, b5));
    // cout << dp(vt-1,k-1 , b5- pt5[vt]) + pt2[vt] << ' ' << dp(vt-1, k, b5) << endl; 
    // cout << vt << ' ' << k << ' ' << ' '<< b5 << ' ' << res << ' '<< pt5[vt]<<  endl;
    return d[vt][k][b5] = res;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    int n,res = 0;
    long long k;
    cin >> n >> k;

    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        long long m = a[i];
        if (m > 1) {
            while (m % 5 == 0) {
                m/= 5;
                pt5[i]++;
            }
            while (m % 2 == 0) {
                m/= 2;
                pt2[i]++;
            }
        }
        //cout << i << ' ' << pt5[i] << ' ' << pt2[i] << endl;
    }

    for (int b5 = 0; b5 <= 3000; b5++) {
        int b2 = dp(n,k,b5);
        res = max(res, min(b2,b5));
    }

    cout << res; 
    return 0;
}
