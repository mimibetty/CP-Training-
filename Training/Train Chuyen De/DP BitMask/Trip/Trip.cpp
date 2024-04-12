// SUBMIT : https://oj.vnoi.info/submission/5292509 trip vnoi
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;
#define bit(n,i) ((n >> i) & 1)

int n;
int a[17][17];
long long dp[65539][17];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

        }
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (__builtin_popcount(mask) == 1 && bit(mask,i) == 1) {
                dp[mask][i] = 0;
            }
            else {
                dp[mask][i] = 1e18;
            }
        }
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int Pos_now = 0; Pos_now < n; Pos_now++) {
            if (bit(mask, Pos_now) == 1) {
                int pre_mask = mask - (1 << Pos_now);       
                if (pre_mask < 0) continue;

                for (int Pos_before = 0; Pos_before < n; Pos_before++) {
                    if (Pos_before != Pos_now && bit(mask,Pos_before) == 1) {
                        dp[mask][Pos_now] = min(dp[mask][Pos_now], 
                            dp[pre_mask][Pos_before] + a[Pos_before][Pos_now]);
                    }
                }
            }
        }
    }
    long long res = 1e18;
    for (int i = 0; i < n; i++) res = min(res, dp[(1 << n) - 1][i]);
    cout << res ;

    return 0;
}