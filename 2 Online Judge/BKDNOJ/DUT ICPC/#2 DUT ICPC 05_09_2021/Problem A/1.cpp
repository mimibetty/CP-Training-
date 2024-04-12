#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n,h,v;
    cin >> n >> h >> v;
    long long res = max({h*v, (n-h) * v, (n-v) *h, (n-v)* (n-h)});
    cout << res * 4;

    return 0;
}