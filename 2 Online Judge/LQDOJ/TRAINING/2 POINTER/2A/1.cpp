#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long k;
    cin >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];
    int vt1 = 0, vt2 = 0;
    long long sum = 0;
    int res = 0;

    while (vt1 <= vt2 && vt2 <= n) {
        if (sum <= k) {
            res = max(res, vt2 - vt1);
            vt2++;
            sum += a[vt2];
        }
        else {
            vt1++;
            sum -= a[vt1];
        }
        //cout << vt1 << ' ' << vt2 << ' '<< sum << ' '<< res << endl;
    }   
    cout << res;
    return 0;
}