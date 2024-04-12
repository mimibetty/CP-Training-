#include<bits/stdc++.h>
using namespace std;

bool snt(long long a) {
    if ( a <= 1) return 0;
    if (a == 2) return 1;
    for (int i = 2; i < a; i++) if (a % i == 0) return 0;
    return 1;
}
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    bool done = 1;
    long long n,tc = 0;
    cin >> n;
    long long k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) done = 0;
    }

    tc = n % 10;
    if (snt(tc) == 0) done = 0;

    if (done == 1) cout << "YES";
    else cout << "NO";
    return 0;
}