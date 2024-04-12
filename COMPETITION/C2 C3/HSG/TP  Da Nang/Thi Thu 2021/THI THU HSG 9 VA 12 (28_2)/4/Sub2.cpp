#include<bits/stdc++.h>
using namespace std;

long long Mod = 1000000007;
int a[100005];
long long preSum[100005];

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
    }
    
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            int sohang = n - j;
            long long val1, val2, val3;
            
            val1 = a[i]%Mod * a[j]%Mod;
            val1 %= Mod;

            val2 = preSum[n] - preSum[j];
            val2 %= Mod; 

          res += ( (val1 * val2) - (a[i]%Mod *(sohang%Mod))%Mod + Mod)%Mod;
          res%=Mod; 
            //cout << i << ' '<< j << ' ';
            //cout << vt1 <<' ' <<vt2 << endl;
        }
    }
    cout << res;
    return 0;
}