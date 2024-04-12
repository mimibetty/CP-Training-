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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool done = 1;
        for (int i = 0; i < n; i++) {
            int vt = i;
            if (s[i] != '?') done = 0;
            while ((s[vt] == 'B' || s[vt] == 'R') && s[vt-1] == '?') {
                if (s[vt] == 'B') {
                    s.insert(vt,"R");
                    s.erase(vt-1,1);
                }
                else {
                    s.insert(vt,"B");
                    s.erase(vt-1,1);
                } 
                vt--;
            }
        }

        for (int i = (n-1); i >= 0; i--) {
            int vt = i;
            while ((s[vt] == 'B' || s[vt] == 'R') && s[vt+1] == '?') {
                //cout << vt << endl;
                if (s[vt] == 'B') {
                    s.erase(vt+1,1);
                    s.insert(vt+1,"R");
                }
                else {
                    s.erase(vt+1,1);
                    s.insert(vt+1,"B");
                } 
                vt++;
            }   
        }

        if (done == 1) {
            s.clear();
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) s += 'R';
                else s += 'B';
            }
        }

        cout << s << endl;
    }
    return 0;
}
// BRRBRBR
// BRBRBRB
// B
// B
// BRRBRBBRBR