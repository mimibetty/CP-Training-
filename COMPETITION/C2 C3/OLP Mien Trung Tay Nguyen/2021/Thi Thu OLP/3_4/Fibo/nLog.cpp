#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n , res = 1e8; 
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++ ) {
            int vt1 = i, vt2 = j;
            int num = 0;
            for (int l = j + 1; l <= n; l++) {
                if (a[l] == a[vt1] + a[vt2]) {
                    vt1 = vt2;
                    vt2 = l;
                    num++;
                }
            }
            res = min(res, n - 2 - num);
        }
    }
    cout << res;
    return 0;
}