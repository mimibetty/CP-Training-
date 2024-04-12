
    #include<bits/stdc++.h>
    using namespace std;

    const long long Mod = 1e9 + 7;
    int n;
    int a[105];
    long long d[1000005];
    bool vs[1000005];


    long long dp(int l) {
        if (vs[l] == 1) return d[l];
        if (l == 0) return 1;

        vs[l] = 1;
        for (int i = 1; i <= n; i++) {
            if (l - a[i] >= 0) {
                d[l] += (dp(l - a[i])%Mod);
                d[l] %= Mod;
            }

        }
        return d[l];
    }

    int main() {
        //freopen("input.txt", "r", stdin);
        ios::sync_with_stdio(0);
        cin.tie(NULL);

        int k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        cout << dp(k);
        return 0;
    }


