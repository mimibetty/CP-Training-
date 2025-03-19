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
     
    int n = 6;
    
    vector<int>a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cin >>x;
        a.push_back(x);
    } 
    for (auto i : a) cout << i << ' ';
    int res = 0;
    for (int i = 0; i < n; i++) {
        int minval = 1e9;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != 0) {
                cnt++;
                minval = min(minval, a[j]);  
            } 
        }
        res += (cnt+1)*minval;
        for (int j = 0; j < n; j++) {
            if (a[j] != 0) {
                a[j] -= minval;
            }
        }
    }
    cout << res <<endl;

    return 0;
}