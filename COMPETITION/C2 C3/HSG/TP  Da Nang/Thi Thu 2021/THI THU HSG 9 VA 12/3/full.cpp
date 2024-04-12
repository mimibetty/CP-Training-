#include<bits/stdc++.h>
using namespace std;

int a[100005];
long long pw4(int k) {
    return k * k * k * k;
}

int main() {
  //  freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res +=  ((n-i) * pw4(a[i])) ; 
       // cout << ((n-i) * pw4(a[i])) << endl;
        
    }
   
    for (int i = 2; i <= n; i++) {
        res -= ( (i-1) *pw4(a[i]) );
    }   

    cout << res;
    return 0;
}