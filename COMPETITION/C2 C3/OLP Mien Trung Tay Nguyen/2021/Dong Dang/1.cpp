#include<bits/stdc++.h>
using namespace std;

long long a[3];
long long b[3];
const int INF = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> a[1] >> a[2] >> b[1] >> b[2];
    sort(a + 1, a + 1 + 2);
    sort(b + 1, b + 1 + 2);
    
    
    long long gcd1 = __gcd(a[1],a[2]);
    long long gcd2 = __gcd(b[1],b[2]);
    if (a[1] / gcd1 == b[1] / gcd2 && a[2] / gcd1 == b[2]/gcd2 ) cout << "YES";
    else cout << "NO";
    return 0;
}