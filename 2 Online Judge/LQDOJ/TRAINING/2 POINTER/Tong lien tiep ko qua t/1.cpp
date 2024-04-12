#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    long long k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0, sum = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        sum += a[r];
        while (sum > k) {
          sum -= a[l];
          l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}