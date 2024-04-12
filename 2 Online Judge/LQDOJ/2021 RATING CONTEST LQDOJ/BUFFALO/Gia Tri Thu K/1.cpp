#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long a[10000005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        long long n,c,k,A,b;
        cin >> n >> c >> k >> A >> b;
        a[1] = A;
        a[2] = b;
        for (int i = 3; i <= n; i++) {
            a[i] = a[i-1]%c + a[i-2]%c;
            a[i] %= c;
        }
        sort(a + 1, a + 1 + n);
        cout << a[k] << endl;
    
    }
    return 0;
}