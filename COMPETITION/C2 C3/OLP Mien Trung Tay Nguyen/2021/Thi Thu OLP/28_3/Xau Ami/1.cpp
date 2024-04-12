#include<bits/stdc++.h>
using namespace std;

int d[305];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    bool done = 1;

    for (int i = 0; i < n; i++) {
        d[(int)s[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if ( d[(int)s[i]] % 2 != 0) {
            done = 0;
            break;
        } 
    }
    
    if (s.size == 0 || done == 0) cout << 0;
    else {
        cout << 1;
    }     
    return 0;
}