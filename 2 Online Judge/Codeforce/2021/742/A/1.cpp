#include<bits/stdc++.h>
using namespace std;

int a[1000005];
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
        int n;
        char x;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x == 'U') cout << 'D';
            else if (x == 'D') cout << 'U';
            else cout <<x;
        }
        cout << endl;
    }
    return 0;
}