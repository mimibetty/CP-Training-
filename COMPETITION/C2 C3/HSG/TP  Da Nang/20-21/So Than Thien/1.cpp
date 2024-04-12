#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    long long a,b;
    cin >> a >> b;

    long long div_a = 0, div_b = 0, can_a = sqrt(a),can_b = sqrt(b);

    for (int i = 1; i <= can_a; i++) {
        if (a % i == 0) {
            div_a += i;
            div_a += (a/i);
        }
    }
    for (int i = 1; i <= can_b; i++) {
        if (b % i == 0) {
            div_b += i;
            div_b += (b/i);
        }
    }
    
    if (can_b * can_b == b) div_b -= can_b;
    if (can_a * can_a == a) div_a -= can_a; 
    
    long long a1,a2,b1,b2;
    a1 = div_a / __gcd(a,div_a);
    a2 = a/ __gcd(a,div_a);

    b1 = div_b / __gcd(b,div_b);
    b2 = b/ __gcd(b,div_b);

    if (a1 == b1 && a2 == b2) {
        cout << a1 << endl;
        cout << a2;
    }
    else cout << -1;
    return 0;
}