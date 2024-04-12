#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t ; q++) {
        int cnt = 0;
        int cs = 0;
        long long sum = 0;
        long long n,k;
        long long res = 0;
        long long maxval = 0, max2 = 1e9;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
            maxval = max ( maxval,a[i].first);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i].first == maxval) cnt++;
        }
        for (int i = 1; i <= n; i++) {
                if (a[i].first == maxval) {
                    max2 = min(max2,a[i].second);
                    cs = i;
                }
        }
        for (int i = 1; i <= n; i++) {
            if (i == cs) sum-=(a[i].first - 1);
            else sum+= (a[i].second - a[i].first + 1);
        }
        cout << sum;
        cout << endl;
    }
    return 0;
}

