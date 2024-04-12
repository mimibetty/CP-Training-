#include<bits/stdc++.h>
using namespace std;

int a[100005];
int x[10000005];
long long pre[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,t;
    cin >> n >> t;

    int maxval = 0;
    for (int i =  1; i <= n; i++) {
        cin >> a[i];
        maxval = max(maxval, a[i]);
    }
    
    for (int i = 1; i <= maxval; i++) {
        x[i] = i;
    }
    int k = sqrt(maxval);

    for (int i = 2; i <= k; i++) {
        if (x[i] == i) {
            for (int j = i * i; j <= maxval; j+= i) x[j] = min(x[j], (int)i);    
        }
    }   

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + 1 + x[a[i]];
      //  cout << pre[i] << ' ';
    }    

    for (int i = 1; i <= t; i++) {
        long long l,r;
        cin >> l >> r;
        long long sum = pre[r] - pre[l-1]; 
        cout << sum;
        cout << endl;
    }

    return 0;
}