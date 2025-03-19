/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 

// pos, num, tight , leadingzero
// tight là giới hạn
// tight = 1 thì tức là các phần tử < pos bằng với các phần trong num => các số tiếp theo sẽ bị
// giới hạn lại sao cho không vượt quá num[pos]
// tight = 0 thì ko bị giới hạn => các phần tử phía sau có thể chọn thoải mái tử 0 - 9

// leading zero là trạng thái chữ số hiện tại có phải là số 0 và trước đó cũng toàn số 0 hay ko
// leading_zero = 1, pos = 2, num = 00123 (bởi vì 2 số liên tiếp = nhau = 0 nhưng nó là số đầu tiên nên cũng ko tính) 

ll dp[20][2][10][2];
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