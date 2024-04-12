#include<bits/stdc++.h>
using namespace std;

long long a[200005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    long long m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a[i] = a[i-1] + k;
  //      cout << a[i] << ' ';
    } 

    int res = 0;
    
    for (int i = 0; i <= n ;i++) {
        
        long long val = m + a[i];
        auto j = lower_bound(a + 1, a + 1 + n,val) - a;
        if (val == j) res++;
        cout << i << ' ' << val << ' '<< j << endl;
    }
    cout << res;
    return 0;
}