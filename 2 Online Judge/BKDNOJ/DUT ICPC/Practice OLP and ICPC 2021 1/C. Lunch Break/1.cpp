#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
long long a[5];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long res = 1e10;
        for (int i = 1 ; i <= 3; i++) {
            cin >> a[i];
            res =min(res, a[i]);  
        } 
        if (res == a[1]) cout << "First";
        else if (res == a[2]) cout << "Second";
        else cout << "Third";
        cout << endl;

    }
    return 0;
}