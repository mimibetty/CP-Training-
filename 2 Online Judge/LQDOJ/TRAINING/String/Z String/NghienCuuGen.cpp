#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
vector<int> zAlgo(string s) {
    int n = s.length();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i <= n - 1; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    vector<int> z;
    cin >> s;
    z = zAlgo(s);
    int n = s.size(), res = 0;
    for (int i = 1; i < n; i++) {
        if (i + z[i] == n) {
            res = i;
            break;
        }
    }
    for (int i = 0; i < res; i++) cout << s[i];
    return 0;
}