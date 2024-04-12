#include<bits/stdc++.h>
using namespace std;

int a[100005];
pair<int,int> x[10000005];
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
        for (int j = 1; i * j <= maxval; j++) {
            if (x[i*j].second >= 2) continue;
            x[i*j].second++;
            x[i*j].first +=  i;
        }
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + x[a[i]].first;
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