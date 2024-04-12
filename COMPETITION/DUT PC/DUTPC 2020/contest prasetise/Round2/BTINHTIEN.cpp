#include <bits/stdc++.h>

using namespace std;

int a[5005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int res = 0;
    for (int i = 1; i <= n - 3; i++) {
        if (a[i] + a[i+1] > a[i+2]) res = max(res, a[i] + a[i+1] + a[i+2]);       
    }
    cout << res;
    return 0;
}
