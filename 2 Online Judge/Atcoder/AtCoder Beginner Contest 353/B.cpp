#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;

 
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
     
    long long n,k;
    cin >> n >> k;
    int res = 1;
    long long cur = 0 ;
    for (int i = 1; i <= n; i++) {
        long long x ;
        cin >> x;
        if (cur + x > k) {
            res++;
            cur = x;
        }
        else {
            cur += x;
        }
    }     
    res = max(res, 1);
    cout << res << endl;

    return 0;
}