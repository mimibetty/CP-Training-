#include <bits/stdc++.h>
 
using namespace std;
 
int a[400005], cnt[3000015], x[3000015];
 
int main() {
   	freopen("input.txt", "r", stdin);
    int n,k;
    cin >> n>> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
 
    // x[k] = so luong a[i] chia het cho k
    for (int i = 1; i <= 3000005; i++) {
        for (int j = 1; i * j <= 3000005; j++) {
            x[i] += cnt[i * j];
        }
    }
 
    int res = 1;
    for (int i = 1; i <= 3000005; i++) {
       if (x[i] >= n-k) {
           res = i;
       }
    }
 
    cout << res << endl;
    return 0;
}