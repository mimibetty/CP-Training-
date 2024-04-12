#include<bits/stdc++.h>
using namespace std;

int a[100005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long sum = 0;
        int gcd = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            gcd = __gcd(gcd,a[i]);
        }
        cout << sum << ' ' << gcd << endl;
    }
    return 0;
}