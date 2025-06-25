#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
bool is_prime[MAX];

// Sieve of Eratosthenes
void sieve() {
    fill(is_prime, is_prime + MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i*i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

// Check if number is prime or differs from prime by at most 1
bool is_near_prime(int num) {
    if (num <= 1) return is_prime[num+1];
    if (is_prime[num]) return true;
    if (num > 0 && is_prime[num-1]) return true;
    if (num+1 < MAX && is_prime[num+1]) return true;
    return false;
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    

    sieve(); // Precompute primes

    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            // mark cell as 1 if near prime, otherwise 0
            a[i][j] = is_near_prime(a[i][j]) ? 1 : 0;
        }
    }

    // Dynamic Programming to find largest square of 1s
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int max_side = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                max_side = max(max_side, dp[i][j]);
            }
        }
    }

    cout << max_side * max_side << '\n';
    return 0;
}