#include<bits/stdc++.h>
using namespace std;

const long long Mod = 1e9+7 ;
long long dp[1000005][2];

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n,m;
    cin >> n >> m;

    long long even = m/2, odd = m/2;
    if (m % 2 != 0) odd++;
    // even = chan , odd = le
    dp[1][0] = even;
    dp[1][1] = odd;

    for (int i = 2; i <= n; i++) {
            dp[i][0] += (dp[i-1][0]%Mod * even%Mod);
            dp[i][0] %= Mod;
            dp[i][1] += (dp[i-1][1]%Mod * even%Mod);
            dp[i][1] %= Mod;

            dp[i][0] += (dp[i-1][1]%Mod * odd%Mod);
            dp[i][1] += (dp[i-1][0]%Mod * odd%Mod);
            dp[i][0] %= Mod;
            dp[i][1] %= Mod;

    }
    cout << dp[n][0] ;
    return 0;
}
