#include<bits/stdc++.h>
using namespace std;

bool vs[100005];
long long d[100005];
const long long Mod = 1e9+7;

long long dp(int x) {
    if (vs[x] != -1) return d[x];
    vs[x] = 1;
    if (x <= 3) return d[x] = 1;

    for (int i = x; i > x - 2; i--) d[x] += dp(x - i);
    return d[x];
} 
 
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    memset(vs, -1 , sizeof(vs));
    int n;
    cin >> n;
    
    d[0] = 1;
    cout << dp(n);
    return 0;
}