#include<bits/stdc++.h>
using namespace std;


const long long Mod = 1e9 + 7;

long long pw(long long x, long long n, long long k) {
    if (n == 0) {
        return 1;
    }
    long long m = pw(x, n / 2, k) % k;
    if (n % 2 == 0) {
        return m * m % k;
    }
    return m * m % k * x % k;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    for (int i = 1; i <= t; i++) {
        long long a,b,c;
        cin >> a >> b >> c;

        // B^c = (mod-1)*n + du
        long long surplus = pw(b,c,Mod-1);
        cout << pw(a,surplus,Mod)<<endl;    
    }
    return 0;
}