#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
long long mod = 1e9 + 7;
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	long long l,r;
 	cin >> l >> r; 
 	long long a =   r - l + 2;
 	long long b =	r - l + 1;
 	if (a % 2 == 0) a/=2;
 	else b/=2;
 	a %= mod;
 	b %= mod;
 	cout << a*b%mod;
    return 0;
}