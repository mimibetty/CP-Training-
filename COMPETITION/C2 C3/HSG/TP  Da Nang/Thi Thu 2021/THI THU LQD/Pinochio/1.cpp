#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;        
    int maxval = 0;
    cin >> n;

    long long m;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxval = max(maxval, a[i]);
    }   

    int lower = 0, upper = maxval;
        
        while (lower < upper) {
            long long mid = (lower + upper) / 2;
            long long k = 0;
            for (int i = 1; i <= n; i++) {
                if (mid < a[i]) {
                    k += (a[i] - mid);
                }
            }
            if (k == m) {
                cout << mid;
                return 0;
            }
            else if (k > m) {
                lower = mid + 1;
            }
            else {
                upper = mid;
            }
            //cout << mid << ' ' << lower << ' ' << upper << ' ' << k << endl;
        }
    cout << lower;
    return 0;
}