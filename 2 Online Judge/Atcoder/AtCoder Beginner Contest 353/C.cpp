#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;

 
ll a[300005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
     
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    ll res = 0;
    const long long modd = 1e8;
    for (int i = 1; i <= n; i++) {
        res = res + a[i] * (n-1) % modd;
        // res %= modd;
        cout << res << endl;
    }
    cout << res << endl;
    cout << modd;
    return 0;
}