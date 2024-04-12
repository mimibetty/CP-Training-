#include<bits/stdc++.h>
using namespace std;
int a[200], b[200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n;
        cin >> n;
        bool done = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] - a[i-1] < 0 || b[i] - b[i-1] < 0) {
                done = 0;
                break;
            }
            if (a[i] - a[i-1] <  b[i] - b[i-1]) {
                done = 0;
                break;
            }
        }
        if (done == 0) cout << "NO";
        else cout << "YES";
        cout << endl;
        for (int i = 1; i <= n; i++) {
            a[i] = 0;
            b[i] = 0;
        }
    }
    return 0;
}
