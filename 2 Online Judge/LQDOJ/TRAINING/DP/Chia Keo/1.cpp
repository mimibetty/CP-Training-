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
        long long x,y;
        int s = 0;
        cin >> x >> y;
        for (int i = 0; i < x; i++) s = (s^i);
        if (s == y) cout << "ok" << endl;
        else {
            for (int i = x+1; i<= 5000; i++) {
                if ((s^i) == y) {
                    cout << i << ' '<< "YES" << end;
                }
            }
        }

    }
    return 0;
}