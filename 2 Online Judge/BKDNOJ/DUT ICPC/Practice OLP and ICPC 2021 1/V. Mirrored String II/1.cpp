#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
string s;
char a[15] =  {'A', 'H', 'I','M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'} ;
int cnt[15];


int d[1005][1005];
int dp(int l, int r) {
    
    if (d[l][r] != -1) return d[l][r];
    if (cnt[s[l]] == 0 || cnt[s[r]] == 0) return d[l][r] = 0;
    if (r == l) return 1;
    if (r == l + 1 && s[l] == s[r]) return 1;


    if (s[l] == s[r] && dp(l + 1, r - 1) == 1) {
        return d[l][r] = 1;
    }
    
    return d[l][r] = 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 0; i < 11; i++) cnt[a[i]] = 1;
    int t;
    cin >> t;

    while(t--) {
        int res = 0;
        cin >> s; 
        int n = s.size();
        
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = -1;
            }
        }

        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp(i,j) == 1) res = max(res, j-i+1);
            }
        }
        cout << res << endl;
        
    
    }
    return 0; 
}