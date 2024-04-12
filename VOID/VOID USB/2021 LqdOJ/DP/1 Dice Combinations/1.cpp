#include<bits/stdc++.h>
using namespace std;

long long dp[1000005];
const long long Mod = 1e9+7;


int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;

 	dp[0] = 1;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= 6; j++) {
 			if (i >= j) {
 				dp[i] += dp[i-j];
 				dp[i] %= Mod;	
 			}
 		}
 	}

 	cout << dp[n];
    return 0;
}