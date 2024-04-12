#include<bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a,h;
        cin >> a >> h;

        double res = h * (log(h) * log(h) - 2* log(h) + 2) / (log(a) * log(a)) - (log(1) * log(1) - 2* log(1) + 2) / (log(a) * log(a));
        cout << setprecision(9) << fixed << ans;
    }

    return 0;
}