#include<bits/stdc++.h>
using namespace std;

int sum(int k) {
    int tong = 0;
    while (k > 0) {
        tong += (k %10);
        k /= 10;
    }
    return tong;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int a,b;
    cin >> a >> b;

    int k = __gcd(a,b);
    int sq = sqrt(k);
    int res = 0;

    for (int i = 1; i <= sq; i++) {
        if (k % i == 0) {
            res = max(res,sum(i));
            res = max(res,sum(k/i));
        }
    }       
    cout << res;
    return 0;
}