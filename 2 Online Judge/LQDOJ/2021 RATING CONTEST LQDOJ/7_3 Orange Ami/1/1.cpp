#include<bits/stdc++.h>
using namespace std;

long long a[200005];
const long long Mod = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n,k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];  
    sort(a + 1, a + 1 + n);
    
    a[1] -= k;
    if (a[1] > 0) {
        long long res = 1;

        for (int i = 1; i <= n; i++) {
            res *= (a[i]%Mod);
            res %= Mod;
        }
        cout << res;
    }
    else cout << 0;

    return 0;
}