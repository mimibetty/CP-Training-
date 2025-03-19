#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[20][2][10][2]; // DP table

ll solve(string &num, int pos, int tight, int prev_digit, int leading_zero) {
    if (pos == num.size()) {
        return 1; // Reached end of number, valid number
    }
    if (dp[pos][tight][prev_digit][leading_zero] != -1) {
        return dp[pos][tight][prev_digit][leading_zero];
    }

    int limit = tight ? num[pos] - '0' : 9;
    ll res = 0;

    for (int digit = 0; digit <= limit; digit++) {
        if (digit == prev_digit && !leading_zero) continue; // Skip if digit is the same as previous digit and not leading zero

        int new_tight = tight & (digit == limit);
        int new_leading_zero = leading_zero & (digit == 0);

        res += solve(num, pos + 1, new_tight, digit, new_leading_zero);
    }

    return dp[pos][tight][prev_digit][leading_zero] = res;
}

ll count_numbers(ll x) {
    if (x < 0) return 0; // Edge case for negative numbers
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(num, 0, 1, 10, 1); // Start with prev_digit = 10, which is not a valid digit, and leading_zero = 1
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    ll a, b;
    cin >> a >> b;

    ll result = count_numbers(b) - count_numbers(a - 1);
    cout << result << endl;
    return 0;
}