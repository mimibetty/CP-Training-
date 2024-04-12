#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();

    bool done = 1;
    for (int i = 0; i < n; i++) {
        a[(int)s[i]]++;     
    }   
    for (int i = 0; i <= 400; i++) {
        if (a[i] % 2 != 0) done = 0;
    }
    if (done == 1) cout << "Yes";
    else cout << "No";
    return 0;
}