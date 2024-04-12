#include<bits/stdc++.h>
using namespace std;
int a[200005];
//int b[2000005];
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    map<int,int>b;
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if ( n <= 1 ) cout << 0;
        else if ( n == 2) cout << 1;
        else {
            set<int>s;
            int res = 0;
            for (int i = 1; i<= n; i++) {
                s.insert(a[i]);
            }
            for (int i = 1; i <= n; i++) {
                b[a[i]]++;
                res = max(res, b[a[i]]);
            }
            int cnt = s.size();
            if (cnt == n) cout << 1;
            else if (cnt == res) {
                cout << cnt-1;
            }
            else cout << min(cnt,res);
//            for(int j = 1; j<= 2e5; j++) {
//                b[j] = 0;
//            }
            b.clear();
            s.clear();
        }
        cout << "\n";
    }

    return 0;
}
