#include<bits/stdc++.h>
using namespace std;
const long long MOD = 10;

long long pw(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(a, n / 2);
    if (n % 2 == 0) {
        return q*q % MOD;
    }
    else {
        return q*q % MOD * a %MOD;
    }
}


int main() {
  	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long a,n;
    cin>>a;
    cin>>n;
    cout<<pw(a,n);



    return 0;
}
