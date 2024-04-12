#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    map<string,long long >d;
    set<string>s;

    for (int i = 1; i <= n; i++) {
        string a,b;
        cin >> a;
        cin >> b;
        int sl;
        cin >> sl;
        d[a]+= sl;
        d[b]+= sl;
        s.insert(a);
        s.insert(b);
    }
    for (auto i : s) cout << i << ' ' << d[i] << endl;
    return 0;
}