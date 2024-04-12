#include<bits/stdc++.h>
using namespace std;
 
string s;
int d[2005][2005];
int d2[2005][2005];
 
int dp(int l, int r) {
    if (r == l) return 1;
    if (r == l + 1 && s[l] == s[r]) return 1;

    if (d[l][r] != -1) return d[l][r];

    if (s[l] == s[r] && dp(l + 1, r - 1) == 1) {
        return d[l][r] = 1;
    }
 
    return d[l][r] = 0;
}

int dp2(int l, int r) {
    if (r == l + 1 && s[r] == s[l]) {
        return d2[l][r] = 2;   
    }
    if (r == l) return d2[l][r] = 1;

    if (d2[l][r] != -1) return d2[l][r];

    if (s[l] == s[r]) {
        return d2[l][r] = dp2(l+1,r-1) + 2;  
    } 

    return d2[l][r] = max(dp2(l+1, r) , dp2(l, r-1));

}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    getline(cin, s);
 
    memset(d, -1, sizeof(d));
    memset(d2, -1, sizeof(d2));

    int res = 0;
    int res2 = 0;
    int n = s.size();
    

    res2 = max(res2, dp2(0,n));       

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dp(i, j) == 1) {
                res = max(res, j - i + 1);
            }        
        }
    }
 
    cout << res << endl << res2;
    
    return 0;
}