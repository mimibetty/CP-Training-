#include<bits/stdc++.h>
using namespace std;
 

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    char a;
    int ketqua = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a >= 'A' && a <= 'Z') ketqua++;
    }
    cout << ketqua ;
    return 0;
}