#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5 + 5;

int a[lim5];
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            bool done = 0;
            for (int j = i + 1; j <= n; j++) {
                if (a[i] < a[j]) {
                    cout << a[j];
                    done = 1;
                    break;
                }
            }
            if (done == 0) cout << -1;
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}