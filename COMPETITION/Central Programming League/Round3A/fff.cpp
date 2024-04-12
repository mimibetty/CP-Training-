#include<bits/stdc++.h>
using namespace std;

bool sohoanhao(long long n) {
    long long x = 1;
    long long can = sqrt(n);
    for (long long i = 2; i <= can; i++) {
        if (n % i == 0) {
            x += i;
            x += (n/i);
        }
    }
    if (can * can == n) x -= can;

    if (x == n) return 1;
    return 0;
} 
bool snt(long long n) {
    if (n < 2) return 0;

    for (long long i = 2; i <= sqrt(n); i++) if (n % i == 0) return 0;
    return 1;
}
int main() {

    long long n;
    cin >> n;
    long long a;
    long long nguyento = 0, hoanhao = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a; 
        if (snt(a)) nguyento++;
        if (sohoanhao(a)) hoanhao++;
    }

    cout << nguyento << ' ' << hoanhao << endl;
    return 0;
}