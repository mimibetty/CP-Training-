#include<bits/stdc++.h>
using namespace std;


int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int q = 1; q <= n; q++ ) {
        string s;
        cin >> s;
        int l = s.size();
        bool done = 0;

        for (int i = 0; i < l; i++) {
            if (s[i] == s[i+1]) done = 1;
        }
        if (done == 1) cout << "YES";
        else cout << "NO";
        cout << endl;
    }   
    return 0;
}