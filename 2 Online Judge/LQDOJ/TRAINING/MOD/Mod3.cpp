#include<bits/stdc++.h>
using namespace std;

long long modMul(long long a, long long b, long long m) {
    if (b == 0) return 0;
    long long s = modMul(a, b / 2, m);
    if (b % 2 == 0) return (s + s) % m;
    else return (s + s + a) % m;
}


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	long long m, n, c ;
 	cin >> m >> n >> c;
 	long long res  =  modMul(m,n,c);
 	cout << res;   
    return 0;
}