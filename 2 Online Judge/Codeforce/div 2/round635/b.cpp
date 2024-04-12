#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n, a,b;

        cin >> n >> a >> b;
        while (n > 0) {
            while (a > 0 && n > 20) {
                n = n/2 + 10;
                a--;
            }
            while (b > 0) {
                n-=10;
                b--;
            }
            if (n <= 0) cout <<"YES";
            else cout << "NO";
            break;
        }
        cout << "\n";
    }
    return 0;
}
