#include<bits/stdc++.h>
using namespace std;


const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
int a[1000005];

int main() {
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t ;

    while (t--) {
        int n;
        cin >> n;
        int cnt = 1;
        int res = 1;
        
        while (cnt < n) {
            res++;
            while (res % 3 == 0 || res % 10 == 3) res++;
            cnt++;
        }
        cout << res << endl;
    }
    return 0;
}