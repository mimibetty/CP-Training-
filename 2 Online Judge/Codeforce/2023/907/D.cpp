/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 


long long fx(long long x) {
    return log2(x);
}
long long gx(long long x) {
    if (x < 8) return 2;
    return log(x) / log(fx(x));
}

const long long modd = 1e9 + 7;
void solve() {
    long long l,r;
    cin >> l >> r;
    // cout << l << ' ' << r <<endl;
    long long res = 0;
    long long f11 = gx(l), f22 = gx(r);
    long long vt = l;
    for (long long i = f11; i <= f22; i++) {
            // cout << "VT  " << i << endl;
            if (i == f22) {
                res += f22*(r-vt + 1)% modd;
                res %= modd; 
            }
            else {
                long long l1 = vt, r1 = r;
                long long val = gx(l1);
                long long mid;
                while (l1 < r1) {
                    mid = (l1 + r1 + 1) /2 ;
                    if (gx(mid) == val) {
                        l1 = mid;
                    }
                    else r1 = mid - 1;
                    // cout << l1 << ' ' << r1 << endl;
                }
                res += (l1 - vt + 1)% modd * gx(l1) % modd;
                res %= modd;
                vt = l1 + 1;
            }

    }
    cout << res << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    // int ff = 50625;
    // cout << log2(ff) << endl;;
    // int cnt = 2;
    int pre = 0;
    for (int i = 1; i <= 10000000; i++) {
        int x = i;
        int fx = log2(x);
        int gx =     log(x) / log(fx);
        if (pre != gx) {
        cout << i << ' ' << fx  << ' ' << gx << endl;
        }
        pre = gx;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}