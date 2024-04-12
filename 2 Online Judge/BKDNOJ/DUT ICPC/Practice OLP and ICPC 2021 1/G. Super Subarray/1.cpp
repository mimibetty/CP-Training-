#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
long long a[2005];
long long ps[2005];
const long long lim = 2000000000000;

bool check(long long a, long long b) {
    a /= __gcd(a,b);
    if (a <= lim/b) return 1;
    return 0;
}
long long lcm(long long a, long long b) {
    a/= __gcd(a,b);
    // if (a > lim/b) return 0;
    return a*b;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] = ps[i-1] + a[i];
        }

        for (int i = 1; i <= n; i++) {
            long long d = a[i];
            for (int j = i; j <= n; j++) {
               if (check(d,a[j]) == 0) break;

                d = lcm(d,a[j]);
                // if (d == 0) break;
                if ((ps[j] - ps[i-1]) % d == 0) {
                    res++;
                   // cout << i << ' ' << j << ' ' <<"LCM: "<< d << ' '<< "SUM: " << ps[j] - ps[i-1] << ' '<< "RES:" << res << endl;  
                } 
            }
        }
        cout << res << endl;
    }    
    return 0;
}