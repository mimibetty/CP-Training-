#include<bits/stdc++.h>
using namespace std;


long long a[200005];
long long combi2(long long x) {
    return x*(x-1)/2;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    map<long long,long long>d;

    long long res = 0;
    long long n,k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] /= k;
        d[a[i]]++;
    }

        // cout << combi2(4);
    for(auto i:d)  res += combi2(i.second);
        cout << res ;
    return 0;
}