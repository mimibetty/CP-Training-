#include <bits/stdc++.h>
using namespace std;

int  a[15];
int main() {

    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
            cout << t <<endl;

        int n;
        // n = 12;
        n = t;
        // cin >> n;
            

            
        for  (int i = 1; i <= n; i++) a[i] = i;

        do {
            map<int,int>d;
            int s = 0;
            bool ok = 1;
            for (int  i = 1; i <= n; i++) {
                s += a[i];
                s %= n;
                d[s+1]++;
                if (d[s] != 1) {
                    ok = 0;
                    break;
                }
            }
            for (auto i : d) {
                cout << i.fi << ' ' << fi
            }
            for (int i = 1; i <= n; i++) {
                if (d[i] != 1) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 1) {
                for (int i = 1; i <= n; i++) cout << a[i] << ' ';
                cout << endl;
                break;    
            }

        } while(next_permutation(a + 1, a + 1 + n) );
    }
    // hoan vi string 
    // string s = "ABCDEG";
    // sort(s.begin(), s.end());

    // do {
    //     cout << s << endl;
    // } while(next_permutation(s.begin(), s.end()) );

    return 0;
}