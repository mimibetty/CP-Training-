#include <bits/stdc++.h>
using namespace std;

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        vector<int> b(d);
        for (int i = 0; i < d; i++) {
            b[i] = v[i % k];
        }
        int score = 0;
        for (int i = 0; i < d; i++) {
            if (b[i] == 1) {
                score += n;
                a.assign(n, 0);
            } else {
                for (int j = 0; j < b[i]; j++) {
                    a[j]++;
                }
            }
            for (int j = 0; j < n; j++) {
                if (a[j] == j + 1) {
                    score++;
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}