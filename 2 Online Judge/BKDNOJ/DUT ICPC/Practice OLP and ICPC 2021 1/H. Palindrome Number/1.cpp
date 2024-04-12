#include<bits/stdc++.h>
using namespace std;

int n,s;
bool check(int n, int s) {
    if (n % 2 == 0 && s % 2 == 1) return 0; 
    if (n == 1 && s > 9) return 0;
    if (n > 1 && (s == 1 || s > 9*n) ) return 0;
    if (n % 2 == 1 && s % 2 == 1 && s < 3 && n != 1) return 0;
    return 1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (check(n,s) == 0) {
            cout << -1 << endl; 
            continue;
        }
        if (n == 1) {
            cout << s << endl;
            continue;
        }

        string res ;
        int plus = 0;

        for (int i = 1; i <= n/2; i++) res += "0"; 
        if (n % 2 == 1  && s % 2 == 1) {
            plus = 1;
            s--;
        }
        int vt = 0;
        while (s > 0 && vt < (n/2)) {
            if (s >= 18) {
                s-=18;
                res[vt] += 9;
            }
            else {
                res[vt] += (s/2);
                s = 0; 
            } 
            vt++;
        }

        if (s > 0) plus += s;
        if (n % 2 == 0) {
            cout << res;
            for (int i = res.size()-1; i >= 0; i--) cout << res[i];
            cout << endl;
        }
        else {
            cout << res << plus;
            for (int i = res.size()-1; i >= 0; i--) cout << res[i];
            cout << endl;   
        }
        res.clear();
    }
    return 0;
}