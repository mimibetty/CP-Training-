#include<bits/stdc++.h>
using namespace std;

string a,b;
int lcs[3005][3005];

int dp (int l, int r) {
    if (lcs[l][r] != -1) return lcs[l][r];
    if (l == 0 || r == 0) return 0;
    if ((l == 1 || r == 1) && a[l] == b[r]) return lcs[l][r] = 1;
    if ((l == 2 || r == 2) && a[l] == b[r]) return lcs[l][r] = 1;
    if (a[l] == b[r]) {
        lcs[l][r] = dp(l-2, r-2) + 1;
        return lcs[l][r];  
    }
    
    return lcs[l][r] = max(dp(l-1, r), dp(l, r-1) );

}


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int q = 1; q <= t; q++) {
        memset(lcs, -1 ,sizeof(lcs) );
        cin >> a >> b;

        int n = a.size();
        int m = b.size();
        int r = max(m,n);

        a = ' ' + a;
        b = ' ' + b;

        cout << dp(n,m) << endl;   
    }
    
    return 0;
}