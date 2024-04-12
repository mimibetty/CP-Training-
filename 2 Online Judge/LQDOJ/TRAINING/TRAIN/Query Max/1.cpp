#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
long long a[200005];
long long ps[200005];
long long cnt[200005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,t;
    cin >> n >> t;
    long long res = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    while (t--) {
        int l,r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r+1]--;
    }

    for (int i = 1; i <= n; i++) {
            ps[i] = ps[i-1] + cnt[i];
    }
    sort(ps + 1, ps + 1 + n);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        res += (a[i]*ps[i]);
    }
    cout << res;
    return 0;
}