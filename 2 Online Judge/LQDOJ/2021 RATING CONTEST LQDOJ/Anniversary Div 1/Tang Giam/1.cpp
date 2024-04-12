#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

double a[3005];
double d[3005][3005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n; 
    
    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i][0] = d[i-1][0] * (1-a[i]); 
    }

    //memset(d, 0 , sizeof(d));
    

    // dp(vt,num) = dp(vt-1, num) * (1-a[i])
    //              dp(vt-1, num-1) * a[i]
    
    for (int vt = 1; vt <= n; vt++) {
        for (int num = 0; num <= vt; num++) {
            
            double up = d[vt-1][num] * (1-a[vt]);
            double ngua = 0;
            if (num - 1 >= 0)  ngua = d[vt-1][num-1] * a[vt];
            
            d[vt][num] = up + ngua;
        }
    }

    double res = 0;
    for (int i = 1; i <= (n/2); i++) {
        res += d[n][i + (n/2)];
        cout << res << endl;
    }
  //  cout << fixed << setprecision(9) << res;
    return 0;
}