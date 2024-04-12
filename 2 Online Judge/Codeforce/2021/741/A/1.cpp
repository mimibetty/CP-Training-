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
        long long a,b;
        cin >> a >> b;  
        if ( b / a == 1) cout << b - a << endl;
        else {

            if (b % 2 == 0) cout << b/2 - 1 << endl;
            else cout << b/2 << endl;
        }
    }
    return 0;
}