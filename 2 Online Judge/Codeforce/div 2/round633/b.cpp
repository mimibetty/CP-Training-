#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n,cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a+ 1 + n);
        if (n % 2 == 0) {
            for (int i = n/2 ; i >= 1; i-- ) {
                cout << a[i] << ' ' << a[n - i + 1] << ' ';
            }
            cout << endl;
        }
        else {
            int  d = n/2 + 1;
            for (int i = d; i >= 1; i--) {
                 if ( i == d )  cout << a[d] << ' ';
                 else cout << a[i] << ' ' << a[n - i + 1] << ' ';
            }
            cout <<endl;
        }
    }
    return 0;
}
