#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t ; q++) {
        long long n,k;
        long long res = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort (a + 1, a + 1 + n);
        if (a[n] < k) cout << 0;
        else {
            bool done = 1;
            int cs = n;
            int sl = 0;
            long long sum = 0;
            while (done == 1 && cs > 0) {
                sum += a[cs];
                sl++;
                if (sum >= sl*k) {
                    done = 1;
                    cs--;
                }

                else {
                    sl--;
                    done = 0;
                }
            }
            cout << sl;
        }
        cout << endl;
    }
    return 0;
}

