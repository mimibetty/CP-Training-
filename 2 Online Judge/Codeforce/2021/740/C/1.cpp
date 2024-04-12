#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
struct number {
    long long val, sl;

    bool operator < (const number &a) {
        if (a.val == val) return sl < a.sl;
        else return val < a.val;
    }
};

number a[100005];
long long ps[100005];
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].sl;
            a[i].val = -1e9;

            for (int j = 1; j <= a[i].sl; j++) {
                long long x;
                cin >> x;
                a[i].val = max(a[i].val, x - j + 2);
            }
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i-1] + a[i].sl;
        }

        long long res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, a[i].val - ps[i-1]);
        }
        cout << res <<endl;

        for (int i = 1; i <= n; i++) {
            a[i] = {0,0};
            ps[i] = 0;
        }
        
        //for (int i = 1; i <= n; i++) cout << a[i].sl << ' ' << a[i].val << endl;    
    }
    
    return 0;
}