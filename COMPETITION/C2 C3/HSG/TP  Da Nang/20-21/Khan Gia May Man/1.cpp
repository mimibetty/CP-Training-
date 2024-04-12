#include<bits/stdc++.h>
using namespace std;

int a[2000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    map<long long, long long>d1,d2;
    int n;
    cin >> n;

    long long res = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        d1[i + a[i]]++;
        if (i - a[i] > 0) d2[i - a[i]]++;
    }
    
    for (int i = 1; i <= n - 1; i++) {
        res += (d1[i] * d2[i]);
    }
    cout << res;
    return 0;
}