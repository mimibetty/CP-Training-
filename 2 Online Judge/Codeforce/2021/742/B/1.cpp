#include<bits/stdc++.h>
using namespace std;

int x[300005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    int s = 0;
    for (int i = 0; i < 300000; i++) {
        s = (s^i);
        x[i] = s;  
    } 
    
    while(t--) {
        long long a,b;
        cin >> a >> b;
        
        if (x[a-1] == b) cout << a;
        else if ((x[a-1]^b) == a) cout << a + 2;
        else cout << a + 1;
        cout << endl;

        // else if (s == 0) {
        //     cout << x + 2;
        // }
        // else if (s == x) cout << x + 1
        // // else cout << x;
        // cout <<s << ' ' << (s^b) << endl;
    }
    return 0;
}