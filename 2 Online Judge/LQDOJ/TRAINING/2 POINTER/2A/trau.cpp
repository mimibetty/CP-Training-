#include<bits/stdc++.h>
using namespace std;

int a[1000005];
long long preS[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,res = 0;
    cin >> n;
    long long k;
    cin >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preS[i] = preS[i-1] + a[i];
    }

    for (int i = 0; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (preS[j] - preS[i] <= k) res = max(res, j - i);
            else break;
        }
    }
    cout << res;
    return 0;
}