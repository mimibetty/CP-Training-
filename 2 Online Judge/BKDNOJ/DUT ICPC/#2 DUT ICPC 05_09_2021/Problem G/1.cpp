#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

string a[10000005];
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
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    bool ok = 0;
    int n;
    map<string,bool>d;
    vector<string>ans;
    cin >> n;
    int maxval = 0;
    int sl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int sl = a[i].size();
        maxval = max(maxval, sl);
        s[sl].push_back(a[i]);
    }
    
    for (int i = 2; i <=  maxval; i++) {
        if (s[i].size() == 0 || s[i-1].size() == 0) {
            continue;
        }
        for (int j = 0; j < s[i].size(); j++) {
            for (int e = 0; e < s[i-1].size(); e++) {
                if (check(s[i][j], s[i-1][e]) == 1) {
                    d[s[i][j]] = 1;
                    ok = 1;  
                } 
            }    
        }
    }

    if (ok == 0) cout << "NO TYPOS";
    else {
        for (int i = 1; i <= n; i++) {
            if (d[a[i]] == 1) cout << a[i] << endl;
        }
    }
    // for (auto i : d) {
    //     ans.push_back(i.first);   
    // }
    // sort(ans.begin(),ans.end());
    // if(ans.size() == 0) cout << "NO TYPOS";
    // else {
    //     for (auto i : ans) cout << i << endl;
    // }
    return 0;
}