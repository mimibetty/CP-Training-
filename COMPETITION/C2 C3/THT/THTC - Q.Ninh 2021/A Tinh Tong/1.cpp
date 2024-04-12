#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n, sum = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sum += i;
        ans += sum;
    }
    cout << ans;
    return 0;
}