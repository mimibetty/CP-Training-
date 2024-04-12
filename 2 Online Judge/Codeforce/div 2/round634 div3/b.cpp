#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n,m,k;
        cin >> n >> m >> k;
        int cs = 97;
        int lim = 97 + k - 1;
        for (int i = 1; i <= n; i++) {
            if (cs >= lim) {
                cout << (char)cs;
                cs = 97;
            }
            else {
                cout << (char)cs;
                cs++;
            }
        }
        cout << "\n";
    }

    return 0;
}
