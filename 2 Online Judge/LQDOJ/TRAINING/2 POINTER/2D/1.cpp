    #include<bits/stdc++.h>
    using namespace std;

    long long a[100005];
    int main() {
        //freopen("input.txt", "r", stdin);
        ios::sync_with_stdio(0);
        cin.tie(NULL);

        int n;
        long long k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) cin >> a[i];

        long long sum = 0;
        long long res = 0;
        long long vtd = 0, vtc = 0;

        while (vtd <= vtc && vtc <= n) {
           // cout << vtd << '  ' << vtc << ' ' << sum << ' ' << res << endl;
            if (sum >= k) {
                res += (n - vtc + 1);
                vtd++;
                sum -= a[vtd];
            }
            else {
                vtc++;
                sum+= a[vtc];
            }

        }
        cout << res;
        return 0;
    }


