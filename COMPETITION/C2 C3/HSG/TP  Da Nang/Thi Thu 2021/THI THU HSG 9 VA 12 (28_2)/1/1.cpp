#include<bits/stdc++.h>
using namespace std;

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int l,r;
    long long k;
    cin >> l >> r >> k;

    long long val_first = 0 , val_final = 0;
    if (k > r) cout << 0;
    else {
        val_final = (r/k);
        val_final *= k;
        
        if (l % k == 0) val_first = l;
        else val_first = l + (k - (l%k) );
       // cout << val_first << ' ' << val_final;

        long long res = 0;
        res = (((val_final - val_first)/k) + 1)  * (val_first + val_final)/2;
        cout << res; 
    }
    return 0;
}