#include <bits/stdc++.h>
using namespace std;

vector<int> num;
long long d[10][200][2];


long long dp(int pos, int sum, bool exceed) {
    if (pos == num.size()) {
        if (num.size() % 2 == 0) {
            return (sum == 101);
        }   
        else return (sum == 99);
    }

    if (d[pos][sum][exceed] != -1) return d[pos][sum][exceed];

    long long ans = 0;

    int lim = 9;
    if (!exceed) lim = num[pos];

    for (int digit = 0; digit <= lim; digit++) {
        bool newExceed = exceed;
        if (digit < lim) newExceed = 1;

        int newSum = sum;
        if (pos % 2 == 0) newSum += digit;
        else newSum -= digit;

        ans += dp(pos + 1, newSum, newExceed);
    }    

    return d[pos][sum][exceed] = ans;
}

long long solve(int a) {
    num.clear();
    while (a > 0) {
        num.push_back(a % 10);
        a /= 10;
    }

    reverse(num.begin(), num.end());

    memset(d, -1, sizeof(d));

    long long res = dp(0, 100, 0);
    return res;
}

int main() {

    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a - 1);
  

    return 0;
}
