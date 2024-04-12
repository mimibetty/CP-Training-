#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[50];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for (int i = 1; i <= 31; i++) {
        b[i] = pow(2,i-1);
    }
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n;
        long long res = 0 ,sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2; i <= n ; i++) {
            long long k = a[i] - a[i-1];
            if (k < 0) {
                sum = max(sum, abs(k));
            }
        }
        int cs = 0;
        int d = 0;
        while (res + b[cs] < sum) {
            res += b[cs];
            cs++;
            d+=cs;
        }
        cout << d;
        cout << "\n";
    }
    return 0;
}
