#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long a[5005];
long long d[5005][5005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    d[0][0] = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            long long b,c;
             b = a[l] + min(d[l+1][r-1], d[l+2][r]);
             c = a[r] + min(d[l+1][r-1], d[l][r-2]);
            d[l][r] = max(b,c);
        }
    }
    cout << d[1][n];
    return 0;
}