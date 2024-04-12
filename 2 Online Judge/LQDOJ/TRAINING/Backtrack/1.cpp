#include<bits/stdc++.h>
using namespace std;


const long long oo = 1e18;
long long res = oo;
long long snt[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long powers[15][40];

long long pw(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    long long q = pw(a,b/2);
    if (b % 2 == 0) return q*q;
    return q*q*a;
}

bool check(long long x, long long y) {
    if (x <= (oo/y)) return 1;
    return 0;
}
void backtrack(long long idx, long long n, long long ans, long long cs) {
    
    if (n == 1) {
        //  cout << idx << ' ' << n << ' ' << ans << endl;
        res = min(res, ans);
        // if (res  == ans) cout << idx << ' ' << ans << endl;
        return;
    }
    if (idx == 10) return;
        // cout << idx << ' ' << n << ' ' << ans << endl;

    for (long long i = 0; i <= cs; i++) {
        if (n % (i+1) == 0) {
            
            if (powers[idx][i] == -1) continue;
            if (check(ans, pw(snt[idx], i)) == 0) continue;
            if (i == 0) backtrack(idx+1, n/(i+1), ans * pw(snt[idx], i), cs);
            else backtrack(idx+1, n/(i+1), ans * pw(snt[idx], i),i);
            
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    snt[10] = oo;
   
    for (int i = 0; i < 10; i++) {
        powers[i][0] = 1;
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 60; j++) {
            if (powers[i][j-1] <= (oo/snt[i])) powers[i][j] = powers[i][j-1] * snt[i];
            else powers[i][j] = -1;            
        }
    }
    
    long long n;    
    cin >> n;    
    long long cs = 60;
    backtrack(0,n,1,cs);
    cout << res; 
    return 0;
}