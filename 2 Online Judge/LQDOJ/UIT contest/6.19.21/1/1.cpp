#include <bits/stdc++.h>
using namespace std;

bitset<16>bs;
int a[20];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,k ;
    cin >> k >> n ;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int maxval =0;
    
    string cur;
    vector<string> ans;
    for (int bit  = 0; bit < (1 << n); bit++) {
        int sum = 0;
        bs = bit;
        string cur;
        for (int i = 0; i < n; i++) {
            cur += bs[i] + '0';
        }

        for (int i = 0; i < n; i++) {
            if (bs[i] == 1) sum += a[i+1];
        }
        if (sum <= k) maxval = max(sum,maxval);
    }
    cout << maxval;


    for (auto s: ans) {
        cout << s << "\n";
    }

    return 0;
}