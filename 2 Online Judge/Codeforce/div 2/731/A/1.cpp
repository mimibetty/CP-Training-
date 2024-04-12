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
    
    int t;
    cin >> t;
    while (t--) {
        int xa,ya,xb,yb,xc,yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;

        if (xa == xb && xb == xc && min(ya,yb) < yc && max(ya,yb) > yc) {
            cout << abs(ya - yb) + 2; 
        } 
        else if (ya == yb &&yb == yc && min(xa,xb) < xc && max(xa,xb) > xc) {
            cout << abs(xa-xb) + 2;
        }
        else cout << abs(xa-xb) + abs(ya-yb);
        cout << endl;
    }   
    return 0;
}