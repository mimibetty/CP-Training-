#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long weight[50], value[50];
long long d[50]; // dp (vi tri)
long long dw[50];

int n;
long long m;

long long dp(int vt) {
    long long res = -1e9;
    if (d[vt] != -1) return d[vt];
    if (d[vt] > m)

    res = max(res, dp(vt+1) + )
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long res = -1e9;
    cin >> n >> m;

    memset(d, -1, sizeof(d));

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++) {
        res = max(res, dp(i));
    }
    cout << res;
    return 0;
}