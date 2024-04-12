#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const int lim3 = 1e3, lim5 = 1e5+5;

int h[1005], s[1005];

int dp[lim5];
int dpOld[lim5];

int n,x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int res = -1e9;
    cin >> n >> x ;
    
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    
    dp[0] = 0;
    for (int i = 1; i <= x; i++) dp[i] = -1e9;

    dpOld[0] = 0;
    for (int i = 1; i <= x; i++) dpOld[i] = -1e9;

    for (int vt = 1; vt <= n; vt++) {
        for (int val = 0; val <= x; val++) {
            dp[val] = -1e9;
            if (val - h[vt] >= 0) {
                dp[val] = max(dp[val], dpOld[val - h[vt]] + s[vt]);  
                //cout << dp[val];
            } 
            dp[val] = max(dp[val], dpOld[val]);

             //cout << ' ' <<dp[val] << endl;
        }

        for (int val = 0; val <= x; val++) {
           dpOld[val] = dp[val];
        }
    }
    
    for (int val = 0; val <= x; val++) {
        res = max(res, dp[val]);
    }
    cout << res;

    // dp(vt,k) = max dp(vt-1, val - h[vt]) + s[vt ]
    //                 dp(vt - 1, val)
    return 0;

}