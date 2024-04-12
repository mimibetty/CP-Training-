#include<bits/stdc++.h>
using namespace std;

int n,m;

int a[105];
int d[1000005];
bool vs[1000005];

int dp(int l) {
    if (vs[l] == 1) return d[l];
    if (l == 0) return 0;

    vs[l] = 1;
    for (int i = 1; i <= n; i++) {
        if (l - a[i] >= 0) {
            d[l] = min(d[l], dp(l - a[i]) + 1);    
        }
    }
    return d[l];
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m ; 

    for (int i = 1; i <= 1e6; i++) d[i] = 1e9;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]] = 1;
        vs[a[i]] = 1;
    }

    if (dp(m) < 1e9) cout << dp(m);
    else cout << -1;
    return 0;
}