#include<bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = 1;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                d[i] = max(d[j] + 1, d[i]);
              //  cout << i << ' ' << j << ' ' << d[j] << endl;
            }
        }
        res = max(res, d[i]);

    }
    cout << res;
   // for (int i = 1; i <= n; i++) cout << i << ' '<< d[i] <<endl;
    return 0;
}
