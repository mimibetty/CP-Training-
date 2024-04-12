#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim4 = 1e4 + 5, lim5 = 1e5;
bool a[lim4];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        int check = -1;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        // check 
        if (a[1] == 1 || a[n] == 0) check = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == 0 && a[i+1] == 1) {
                check = 1;
            }
        }

        if (check == -1) cout << -1 << endl;
        else {
            if (a[1] == 1) {
                cout << n + 1 << ' ';
                for (int i = 1; i <= n; i++) cout << i << ' ';
                cout << endl; 
            }
            else if (a[n] == 0) {
                for (int i = 1; i <= n; i++) cout << i << ' ';
                cout << n + 1 << ' ';
                cout << endl;   
            }
            else {
                bool done = 0;
                int i = 1;
                while (i <= n) {
                    if (done == 1) {
                         cout << i << ' ';
                         i++;   
                    }
                    else {
                        if (a[i] == 0 && a[i+1] == 1) {
                            done = 1;
                            cout << i << ' ' << n+1 << ' ' << i+1 <<' ';
                            i += 2; 
                        }
                        else {
                            cout << i << ' ';
                            i++;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}