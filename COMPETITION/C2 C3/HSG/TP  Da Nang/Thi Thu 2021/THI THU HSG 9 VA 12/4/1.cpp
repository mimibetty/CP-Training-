#include<bits/stdc++.h>
using namespace std;

int a[1000005];
long long dp[100005];


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    int k;
    cin >> k;

    int x;
    for (int i = 1; i <= x; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < k; i++) dp[1][i] = 0;
    dp[1][0] = 1;


    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int p = a[i] % k;
            
            if (p == 0) {
                dp
            }
        }
    }

    return 0;
}