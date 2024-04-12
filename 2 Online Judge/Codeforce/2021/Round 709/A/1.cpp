#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int d[1000005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n,x;
    int res = 0;
    cin >> n >> x;

    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    sort (a + 1,a + n + 1);

    for (int i = 1; i <= n; i++) {
        int k = a[i];
        res += d[x - k];
    }
    cout << res / 2;

    return 0;
}