#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long k;
    cin >> k;

    long long tong = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tong += a[i];
    }

    int vt1 = 0, vt2 = 0;
    long long sum = 0;
    int res = 1e9;

    while (vt1 <= vt2 && vt2 <= n) {
        if (sum >= k) {
            res = min(res, vt2 - vt1);
            vt1++;
            sum -= a[vt1];
        }
        else {
            vt2++;
            sum += a[vt2];

        }
        //cout << vt1 << ' ' << vt2 << ' '<< sum << ' '<< res << endl;
    }
    if (tong < k) cout << -1;   
    else cout << res;
    return 0;
}