#include<bits/stdc++.h>
using namespace std;


bool check(string &s,int sl , int n) {
    for (int j = sl-1; j < n; j+= (sl+1)) {
        // cout << "VT" << ' ' << j << endl;
        // cout << s[j] << ' ' << s[j+1] << endl;
        if (s[j] >= 'a' && s[j] <= 'z') {
                if (s[j+1] ==  '#') return 1;
                if (s[j+1] == ' ')  {

                }
                if (s[j+1] >= 'a' && s[j+1] <= 'z') return 0;
        }
        else return 0;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline (cin, s);

        vector<int>a;
        int n = s.size();
        for (int i = 2; i <= sqrt(n+1); i++) {
            if ((n+1) % i == 0) {
                if (i != (n+1)/i) a.push_back((n+1)/i);
                a.push_back(i);
            } 
        }


        bool ok = 0;
        s+= '#';

        for (auto i : a) {
            int sl = i-1;
            if (check(s,sl,n) == 1) {
                ok = 1;
                break;
            }
        }

        if (ok == 1) cout <<"YES";
        else cout << "NO";
        cout << endl;
        a.clear();
    }
    return 0;
}