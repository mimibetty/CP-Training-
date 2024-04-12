#include<bits/stdc++.h>
using namespace std;

int a[100005];
int d[100005];
int n,k;

int dp(int l) {
    if (d[l] != 1e9) return d[l];
    
    if (l == 1 || l == 0) return 0;
    if (l > 1 && l <= k + 1) return d[l] = abs(a[l] - a[1]);
    
    if (l > k + 1) {
        for (int i = 1; i <= k; i++) {
                d[l] = min( dp(l-i) + abs(a[l] - a[l-i]) , d[l]);
        }
        return d[l];
    }
}   

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k; 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = 1e9;
    }   

   // for (int i = 1; i <= n;i++) cout << d[i] << endl;
    cout << dp(n);
    return 0;
}