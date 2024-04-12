#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int dp[100005];
int trace[100005];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    sieve(10000);

    vector<int> primes;
    for (int i = 1; i <= n; i++) {
    	if (trace[i] == i) {
    		primes.push_back(i);
    	}
    }

    for (int i = 1; i <= 10000; i++) {
    	dp[i] = 1e9;
    }

    for (int i = 2; i <= n; i++) {
    	for (auto j: primes) {
    		if (j > i) break;

    		dp[i] = min(dp[i], dp[i - j] + 1);
    	}
    }
    cout << dp[n];

    return 0;
}