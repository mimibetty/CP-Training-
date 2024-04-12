#include<bits/stdc++.h>
using namespace std;
char a[20][20];
int k[20] = {1,4,7,2,5,8,3,6,9};
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //    for (int i = 0; i<= 8; i++) cout << k[i] << ' ';
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cin >> a[i][j];
               // cout << a[i][j];
               int d = a[i][j] - '0';
               if (j == k[i-1]) {
                    if (d == 9 ) a[i][j] = (d - 1) +'0' ;
                    else a[i][j] = (d + 1) +'0';
                }
            }
        }
        cout << endl;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
            cout << a[i][j];

            }
            cout<< "\n";
        }
    }
    return 0;
}
