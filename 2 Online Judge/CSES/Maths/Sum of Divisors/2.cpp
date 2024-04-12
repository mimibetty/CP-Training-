#include<bits/stdc++.h>
using namespace std;

const long long Mod = 1e9 + 7;

long long solve(long long a, long long b) {
    long long x = b+a;
    long long y = b-a+1;        
    if (y % 2 == 0) y /= 2;
    else x /= 2;

    x %= Mod; y %= Mod;
    return x * y % Mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n , sum = 0;
    cin >> n;

    long long can = sqrt(n);
    long long k =  n/(can+1);
    for (long long i = 1; i <= can; i++) {
        // xu li duoi can
        sum += ((n/i) * i%Mod);
        sum %= Mod;
    }

    for (long long i = 1; i <= can; i++) {
        long long num_end = (n/i);
        long long num_begin = ceil(n * 1.0/(i+1));
        if (num_begin == n/(i+1)) num_begin++;
        if (num_begin <= can) num_begin = can + 1;

        sum += (i%Mod * solve(num_begin,num_end)%Mod);
        sum %=Mod;
       // cout << num_begin << ' ' << num_end <<endl; 
    }
    
    cout << sum;
    return 0;
}