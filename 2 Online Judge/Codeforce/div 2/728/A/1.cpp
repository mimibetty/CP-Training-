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
    for (int q = 1 ; q <= t; q++) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0) cout << i - 1 << ' ';
                else cout << i + 1 << ' ';
            }
        }
        else {
            for (int i = 1; i <= n - 3; i++) {
                if (i % 2 == 0) cout << i - 1 << ' ';
                else cout << i + 1 << ' ';
            }   
            cout << n - 1 << ' ' << n << ' ' << n - 2;
        }
        cout << endl;
    }   
    return 0;
}