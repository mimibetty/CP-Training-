#include<bits/stdc++.h>
using namespace std;

map <long long,long long> a;
int main() {
  freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin >> n;
        //2 3 4
    if (n > 1e7) {
        cout << 0;
        return 0;
    }
    //cout << (5 + 3) * (5 - 3 + 1) / 2;

    for (int i = 2; i * i <= n; i++) {
        cout << i;
        for (int j = i + 1; j <= n / 2; j++) {
            cout << (j + i) * (j - i + 1) / 2 << endl;
            //if ((j + i) * (j - i + 1) / 2 == n) cout << j - i + 1;
        }
    }
    

    return 0;
}