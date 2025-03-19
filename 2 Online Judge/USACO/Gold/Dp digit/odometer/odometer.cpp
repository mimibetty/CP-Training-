/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 

// https://usaco.org/index.php?page=viewproblem2&cpid=435
// pos, number at pos, cnt number, tight, leading zero;
ll dp[20][10][20][2][2];
long long solve(const string &num, int pos, int tight, int pre_digit, bool leading_zero) {
    if (pos == num.size()) {
        return 1;
    }

    if (dp[pos][tight][pre_digit][leading_zero] != -1) {
        return dp[pos][tight][pre_digit][leading_zero];
    }

    // int limit = tight ? num[pos] - '0' : 9;
    int limit;
    if (tight == 1) {
        limit = num[pos] - '0';
    }
    else limit = 9;

    ll res = 0;
    for (int digit = 0; digit <= limit; digit++) {
        if (digit == pre_digit && leading_zero == 0) continue; 
        
        int new_tight = tight & (digit == limit);
        int new_leadingzero = leading_zero & (digit == 0); 
        res += solve(num, pos + 1, new_tight, digit, new_leadingzero);
    }

    return dp[pos][tight][pre_digit][leading_zero] = res;
}


long long countDp(ll x) {
    if (x < 0) return 0; // Edge case for negative numbers
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(num, 0, 1, 10, 1);
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

       
    ll a,b;
    cin >> a >> b;
    ll res = countDp(b) - countDp(a-1);
    cout << res << endl;
    return 0;
}