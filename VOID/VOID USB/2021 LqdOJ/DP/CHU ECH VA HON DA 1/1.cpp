#include<bits/stdc++.h>
using namespace std;

int a[100005];
int d[100005];
int n;

int dp(int l) {
    if (d[l] != -1) return d[l];
    
    if (l == 1 || l == 0) return 0;
    if (l == 2) return d[l] = abs(a[l] - a[1]);
    
    if (l >= 2) return d[l] = min(dp(l-2) + abs(a[l] - a[l-2]) , dp(l-1) + abs(a[l] - a[l-1]));
}   

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    memset(d, -1, sizeof(d));
    cin >> n; 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   

    cout << dp(n);
    return 0;
}