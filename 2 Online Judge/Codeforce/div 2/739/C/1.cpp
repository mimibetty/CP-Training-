#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long lay=1;
        for (long long i = 1; i <= 1e5; i++) {
            if (n > (i*i)) lay = i+1;
            if ( n < (i * i)) break;
        }
        long long sl = 1 + (lay-1)*2;
        long long vt = n - (lay-1)*(lay-1);
        long long x = 0, y = 0;
        if (vt <= lay) {
            x = lay;
            y = vt ;
        }
        else {
            y = lay;
            x = (2*lay) - vt ;
        }
        // cout << vt;
        // cout << endl;
        cout << y <<  ' ' << x <<endl;
    }
    return 0;
}