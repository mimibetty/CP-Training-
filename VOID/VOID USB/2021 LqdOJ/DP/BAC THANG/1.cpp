#include<bits/stdc++.h>
using namespace std;


const long long MOD = 14062008; 
int a[100005];
long long d[100005];

long long dp(int x) {  
    if (d[x] != -1) return d[x]%MOD;
    if (a[x] == 1) return d[x] = 0;
    if ( x == 0) return 0;
    if ( x == 1 || x == 2) return 1;
    
      //  cout << x << endl;

    d[x] = dp(x-1)%MOD + dp(x-2)%MOD;
    return d[x]%MOD;

}
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(a, -1, sizeof(a));
    memset(d, -1, sizeof(d));

    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        a[k] = 1;
    }

    cout << dp(n);
    return 0;
}