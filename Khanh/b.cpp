#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 1e9 + 7;
long long dp[100002];
long long prefixSum[100002];

void solve() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        fill(dp, dp + n + 1, 0);
        fill(prefixSum, prefixSum + n + 1, 0);
        
        dp[0] = 1;  // Base case
        prefixSum[0] = 1;
        
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i - k >= 0) {
                dp[i] = prefixSum[i - 1];
            } 
            prefixSum[i] = (prefixSum[i - 1] + dp[i]) % MOD;
            sum = (sum + dp[i]) % MOD;
        }
        cout << sum << endl;
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
