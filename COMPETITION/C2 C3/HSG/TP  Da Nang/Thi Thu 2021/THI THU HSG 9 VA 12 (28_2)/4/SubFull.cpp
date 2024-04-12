#include<bits/stdc++.h>
using namespace std;

long long Mod = 1000000007;
int a[100005];
long long preSum[100005];
long long preX[100005];
long long preAns[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preSum[i] = a[i] + preSum[i-1];
        
        preX[i] = preSum[i-1] * a[i];
        //cout << preX[i] << ' ';
    }
    
    preX[1] = 0;
    for (int i = 2; i <= n; i++) {
        preAns[i] = preX[i] + preAns[i-1];
        cout << i << ' ' << preAns[i] << endl;
    }

    for (int i = n - 1; i >= 2; i--) {
        long long val1 = preSum[n] - preSum[i];
            
       // cout << i << ' ' << val1 << ' ' << val2 << ' ' << val3 << ' ' << ((val1 * val2 * val3) - preSum[i-1]) << endl; 
        res += (val1 * preAns[i]);
    }
    cout << res;
    return 0;
}