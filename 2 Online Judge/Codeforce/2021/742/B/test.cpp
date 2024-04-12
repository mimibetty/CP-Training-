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

    while(t--) {
            int s = 0;
        long long x,y;
        cin >> x >> y;
        for (int i = 0; i < x; i++) s = (s^i);
        // if (x == y) cout << x+2;
        // else if (y == 0 || x < y) cout << x+1;
        // else cout << x;
        cout <<s <<  endl;
    }
    return 0;
}