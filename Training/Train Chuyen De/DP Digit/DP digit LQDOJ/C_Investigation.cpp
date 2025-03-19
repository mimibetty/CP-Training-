#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> num;
long long d[10][100][100][2];

long long dp(int pos, int val, int sum, bool exceed) {
    if (pos == num.size()) {
        return (val == 0 && sum == 0);
    }

    if (d[pos][val][sum][exceed] != -1) return d[pos][val][sum][exceed];

    long long ans = 0;

    int lim = 9;
    if (!exceed) lim = num[pos];

    for (int digit = 0; digit <= lim; digit++) {
        bool newExceed = exceed;
        if (digit < lim) newExceed = 1;

        int newVal = (val * 10 + digit) % k;
        int newSum = (sum + digit) % k;
        ans += dp(pos + 1, newVal, newSum, newExceed);
    }    

    return d[pos][val][sum][exceed] = ans;
}

long long solve(int a) {
    num.clear();
    while (a > 0) {
        num.push_back(a % 10);
        a /= 10;
    }

    reverse(num.begin(), num.end());

    memset(d, -1, sizeof(d));

    long long res = dp(0, 0, 0, 0);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b >> k;

    if (k > 100) cout << 0;
    else {
        cout << solve(b) - solve(a - 1);
    }

    return 0;
}
