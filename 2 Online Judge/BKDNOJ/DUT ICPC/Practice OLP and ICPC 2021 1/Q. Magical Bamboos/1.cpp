#include<bits/stdc++.h>
using namespace std;

int a[100005];
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
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even = 1;
            else odd = 1;
        }
        if (even == odd) cout << "no";
        else cout << "yes";
        cout << endl;
    } 
    return 0;
}