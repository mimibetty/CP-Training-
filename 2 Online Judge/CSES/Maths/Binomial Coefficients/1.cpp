#include<bits/stdc++.h>
using namespace std;

const long long Mod = 1e9 + 7;
const int lim = 1e6 ;

long long fact[1000005], inv[1000005]; // size of array =  lim + 5

long long pw(long long a, long long b) {
    if (b == 1) return a;
    if (b == 0) return 1;
    long long q = pw(a, b/2) % Mod;
    if (b % 2 == 0) return q%Mod * q%Mod;
    else return q%Mod * q%Mod * a%Mod; 
}

long long combi(long long a,long long b) {
    if (a >= b) return fact[a]%Mod * inv[b]%Mod * inv[a-b]%Mod;
    return 0; 
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    fact[0] = 1;
    inv[0] = 1;

    for (long long i = 1; i <= lim; i++) {
        fact[i] = i * fact[i-1] % Mod;
    }

    inv[lim] = pw(fact[lim],Mod-2);
    for (long long i = (lim-1); i >= 1; i--) {
        inv[i] = inv[i+1] * (i+1) % Mod;
    }

    int t;
    cin >> t;

    for (int q = 1; q <= t; q++) {
        long long b,a;
        cin >> a >> b;
        cout << combi(a,b) << endl;
    }   
    return 0;
}