#include<bits/stdc++.h>
using namespace std;

long long a[100005];
map<long long,long long>d;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n,ans=0;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }

    long long res = 0;
    for (long long i = 1; i <= n; i++) {
        long long k = a[i] * d[a[i]];
        if (k > res ) {
            res = k;
            ans = a[i];
        }
        else if (k == res) ans = max(ans,a[i]);
       
    }
    
    cout << ans;
    return 0;
}