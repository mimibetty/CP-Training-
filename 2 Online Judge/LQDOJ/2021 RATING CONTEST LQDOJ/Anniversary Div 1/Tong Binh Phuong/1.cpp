#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long solve(long long n) {
    long long sl = n/2;
    long long ans = 0;
    ans = sl*(6 + 4*(sl-1));
    return ans/2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long n,ans = 0;
        cin >> n;
        if (n % 2 != 0) {
            ans -= (n*n);
        }
        ans += solve(n);
        cout << ans << endl;
    }
    return 0;
}