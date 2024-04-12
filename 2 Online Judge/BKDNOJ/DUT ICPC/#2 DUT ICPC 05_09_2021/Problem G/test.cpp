#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

vector<string>s[10000005];
bool check(string &a, string &b) {
    int cnt = 0;
    int vt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[vt]) {
            vt++;
        }
        else {
            cnt++;
        }
        if (cnt >= 2) return 0;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a;
    int n;
    map<string,bool>d;
    vector<string>ans;
    cin >> n;
    int maxval = 0;
    int sl;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        int sl = a.size();
        maxval = max(maxval, sl);
        s[sl].push_back(a);
    }
    
    string s1= "hoose";
    string s2 = "hosee";
    cout << check(s1,s2);
    return 0;
}