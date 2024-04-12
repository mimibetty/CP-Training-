#include<bits/stdc++.h>
using namespace std;


const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long a[3005];
bool check[3005][3005];
long long d[3005][3005];

long long dp(int l, int r) { // turn = 1 X, turn = 2 Y
    if (check[l][r] != 0) return d[l][r];
    if (l == r) {
        return d[l][r] = a[l];
    }
    if ( l > r) {
        return d[l][r] = 0;
    } 
    long long res = 0;
    
    long long b1 = a[l] + min(dp(l+2, r), dp(l+1, r-1));
    long long b2 = a[r] + min(dp(l+1, r-1), dp(l, r-2));
    res = max(b1,b2);

    check[l][r] = 1;
    return d[l][r] = res; 
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];  
    } 

    memset(check, 0, sizeof(check));

    long long x = dp(1,n);
    long long y = sum - x;
    cout << x - y;
    return 0;
}