#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005][5];
int d[100005][5];

int dp(int l, int r) {
    if (d[l][r] != -1) return d[l][r];
    if (l == 0) return 0;

    if (l >= 1) {
        for (int i = 1; i <= 3; i++) {
                if (i != r) {
                       d[l][r] = max(d[l][r], dp(l-1,i) + a[l][r]);           
                }                
            }
        }
        return d[l][r];
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
      
    
    cin >> n;
    memset(d, -1 ,sizeof(d));

    for (int i = 1; i <= n ; i++) cin >> a[i][1] >> a[i][2] >> a[i][3] ;

    cout << max( max( dp(n,1), dp(n,2) ), dp(n,3) );
    return 0;
}