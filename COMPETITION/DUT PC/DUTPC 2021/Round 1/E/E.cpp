#include<bits/stdc++.h>
using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string c,key2, key1;
    cin >> c >> key2;

    key1 = key2;

    int nc = c.size();
    int nk = key1.size();
    
    int k = nc/nk;
    int m = nc%nk;
//    cout << k << m;
    for (int i = 1; i < k; i++ ) {
        key1 += key2; 

    }
    for (int i = 1; i <= m; i++) {
        key1 += key2[i-1];
    }

    for (int i = 0; i < nc; i++) {
        int num = int(c[i]) -int(key1[i]);
        //cout << num;
        if (num < 0) num = 26 + num;
        cout << (char) (num + 65);
    }
    return 0;
}