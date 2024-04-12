#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    double res = 1;
    double x = 1;
    for (int i = 1; i <= n; i++) {
        x = 1;
        for (double j = 1; j <= i; j++) {
            x = double(x/j);
        }
        res += x;
    }

    cout << fixed << setprecision(12) << res;
    return 0;
}