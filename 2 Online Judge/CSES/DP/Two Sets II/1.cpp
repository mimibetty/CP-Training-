#include<bits/stdc++.h>
using namespace std;

//long long  a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const long long  lim3 = 1e3, lim5 = 1e5;

long long pw(long long a, long long b) {
    if (b == 1) return a;
    if (b == 0) return 1;
    long long q = pw(a, b/2) % Mod;
    if (b % 2 == 0) return q%Mod * q%Mod;
    else return q%Mod * q%Mod * a%Mod; 
}
 

long long d[505][70000];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long  n;
    cin >> n;
    long long  sum = n*(n+1);
    sum/=2;

    if (sum % 2 != 0) {
        cout << 0;
        return 0;
    }

    d[0][0] = 1;

    for (long long  vt = 1; vt <= n; vt++) {
        for (long long  val = 0; val <= (sum/2); val++) {
            d[vt][val] += (d[vt-1][val]%Mod);
            d[vt][val] %= Mod;
            if (val - vt >= 0) {
                d[vt][val] += (d[vt-1][val - vt]%Mod);
                d[vt][val] %= Mod;
            }

        }
    }
    
    cout << d[n][sum/2] * pw(2, Mod - 2) % Mod;
    return 0;
}