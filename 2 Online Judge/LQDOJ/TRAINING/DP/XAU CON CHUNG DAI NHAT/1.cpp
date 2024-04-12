#include<bits/stdc++.h>
using namespace std;

string a,b;
int trace[3005][3005];
int lcs[3005][3005];

int dp (int l, int r) {
    if (lcs[l][r] != -1) return lcs[l][r];
    if (l == 0 || r == 0) return 0;
    if (a[l] == b[r]) {
        lcs[l][r] = dp(l-1, r-1) + 1;
        trace[l][r] = 1;
        return lcs[l][r];  
    }
    if (dp(l-1,r) > dp(l,r-1) ) trace[l][r] = 2;
    else trace[l][r] = 3;

    return lcs[l][r] = max(dp(l-1, r), dp(l, r-1) );

}


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(lcs, -1 ,sizeof(lcs) );
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    int r = max(m,n);

    a = ' ' + a;
    b = ' ' + b;

    dp(n,m);

    if (lcs[n][m] > 0) {
        vector<char>strmax;
        int x = n, y = m;
        while (x >= 1 && y >= 1) {
            if (trace[x][y] == 1) {
                strmax.push_back(a[x]);
                x--;
                y--;
            }
            else if (trace[x][y] == 2) {
                x--;
            }
            else if (trace[x][y] == 3) {
                y--;
            }  
        }
        reverse(strmax.begin(),strmax.end());
        for (auto i : strmax) cout << i;   
    }
    return 0;
}