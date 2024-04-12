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
    int t;
    cin >> t;
    while (t--) {
        long long a,b;
        cin >> a >> b;
        if (a == 0 && b == 0) cout << 0 ;
        else if (a == b) cout << 1;
        else if (abs(a + b) % 2 == 0) cout << 2;
        else cout << -1; 
        cout << endl;
    }   
    return 0;
}