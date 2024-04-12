#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int eulerPhi(int n) { // = n (1-1/p1) ... (1-1/pn)
    if (n == 0) return 0;
    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int phi[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 1; i <= 1e6; i++) {
        phi[i] = eulerPhi(i);
        //cout << phi[i] << endl;
    }

    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        else {
            int res = 0;
            //res += (n - 1);
            for (int i = 1; i <= n; i++) {
                //cout << i << ' ' << phi[i] << endl;
                res += (phi[i] / 2);
                res += i *  ((n - i) / i); 
            }
            cout << res << endl;      
        }
    }
    
    return 0;
}