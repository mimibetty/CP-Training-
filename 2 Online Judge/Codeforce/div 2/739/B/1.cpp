#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c;
        cin >> a >> b >> c;
        
        long long kc = abs(a-b);        
            kc--;
            long long sl = (2*kc) + 2;

            if (c > sl || max(a,b) > sl) cout << -1;
            else if (c >= (sl-kc)) {
                if (c - kc - 1 >= 1) cout << c - kc - 1;
                else cout << -1;
            } 
            else  {
                if (c + kc + 1 <= sl) cout << c + kc + 1;
                else cout << -1;
        }
        cout << endl;
    }
    return 0;
}