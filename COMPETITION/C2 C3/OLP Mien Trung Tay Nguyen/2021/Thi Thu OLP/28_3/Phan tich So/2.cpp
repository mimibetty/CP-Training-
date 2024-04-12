#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 0; i <= 3; i++) a[i] =1;
    a[4] = 2;
    a[5] = 2;
    a[6] = 3;
    a[7] = 3;
    a[8] = 4;
    for (int i = 9; i <= 12; i++ ) a[i] = 5;

    int n;
    cin >> n;
    if (n <= 12) cout << a[i];
    else cout << 6 ;   
    return 0;
}