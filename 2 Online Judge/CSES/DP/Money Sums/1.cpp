#include<bits/stdc++.h>
using namespace std;

int a[105];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int d[105][100005];
int n;

int dp(int vt, int val) {
    
    if (vt < 0 || val < 0) return 0;
    if (vt == 0) {
        if (val == 0) return 1;
        else return 0;
    }
    if (d[vt][val] != -1) return d[vt][val];

    return d[vt][val] = (dp(vt-1,val)|dp(vt-1,val - a[vt]));

}
   

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int ans = 0;
    vector<int>cs;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    memset(d, -1 , sizeof(d));

    for (int val = 1; val <= 1e5; val++) {
        if (dp(n,val) == 1) {
            ans++;
            cs.push_back(val);  
        } 
    }

    cout << ans << endl;
    for (auto i : cs) cout << i << ' ';
    return 0;
}