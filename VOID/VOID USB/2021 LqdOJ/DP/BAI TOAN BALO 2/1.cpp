#include<bits/stdc++.h>
using namespace std;

int a[105],b[105];
long long d[105][100005];

// vi tri , tien , trong luong

// dp ( vi tri , tien)
long long dp(int l, int r) {
   // cout << l << ' ' << r << endl;
    if (d[l][r] != 1e9) return d[l][r];

    if (l == 0 && r == 0) return d[l][r]  = 0;

    d[l][r] = min(dp(l-1, r - b[l]) + a[l], dp(l-1, r) );
    return d[l][r];
    
    }

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    //memset(d, -1 , sizeof(d));
    
    int res = 0;
    int n,m,sumMoney = 0;
    cin >> n >> m;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 1e5; j++) {
            d[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sumMoney += b[i];
    }

    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 140; j++) {
            cout << i << ' ' << j << ' ' << dp(i,j) << endl; 
        }
    }
/*    for (int j = 1; j <= sumMoney; j++) {
      // cout <<j << ' '<< dp(n,j) << endl;
       if (dp(n,j) <= m) res = j;
    }
    cout << res ;*/
    return 0;
}

