#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int res = 0;
    int n,p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) if (__gcd(i,n) == p) res++;
        cout << res;
    return 0;
}