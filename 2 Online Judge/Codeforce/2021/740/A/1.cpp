#include<bits/stdc++.h>
using namespace std;


const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim = 1e5 + 5;
int a[1005];
int b[1005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];
        bool check = 1;
        int res = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] > a[i+1]) {
                check = 0;
                break;
            }
        }
        //cout << t << ' ';
        
        if (check == 1) cout << 0 << endl;
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < n; j++) {
                    if (abs(j-i) % 2 == 0) {
                        if (a[j] > a[j+1]) {
                          swap(a[j], a[j+1]);
                        } 
                    }
                }
                res++;
                check = 1;
                for (int j = 1; j < n; j++) if (a[j] > a[j+1]) {
                    check = 0;
                    break;
                }
                if (check == 1) {
                    cout << res << endl;
                    break;
                }
            }
        }
    } 
    return 0;
}