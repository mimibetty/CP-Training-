#include<bits/stdc++.h>
using namespace std;

int a[1005];
int INF = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int res = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        a[(int)s[i]]++;
    }

    bool Mod1 = 0;
    for (int i = 1; i <= 400; i++) {
        if (a[i] >= 2) res += (a[i]/2)*2;
        if (a[i] % 2 != 0) Mod1 = 1; 
    }
    cout << s.size() - (res +Mod1);
    return 0;
}