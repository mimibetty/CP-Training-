#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long k = (a[i] - a[j]) * (a[i] + a[j]) * ((a[i] * a[i]) + (a[j] * a[j]));
            res += k;
        }
    }
    cout << res;
    return 0;
}