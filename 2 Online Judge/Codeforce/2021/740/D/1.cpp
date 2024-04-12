#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

long long dp[200005];
long long ps[200005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n,m;
    cin >> n >> m;

    dp[1] = 1;
    ps[1] = 1;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j < i; j++) {
    //         dp[i] += (dp[i-j]%m);
    //         dp[i] %=m;
    //     }
    //     for (int j = 2; j <= i; j++) {
    //         dp[i] += (dp[i/j]%m);
    //         dp[i] %= m;
    //     }
    // }

    for (int i = 2; i <= n; i++) {
        dp[i] += (ps[i-1]%m);
        dp[i] %= m;

        // /= 2 > i
        
        ps[i] = (ps[i-1] + dp[i])%m;
        ps[i] %= m;
    }
    cout << dp[n] % m;
    return 0;
}