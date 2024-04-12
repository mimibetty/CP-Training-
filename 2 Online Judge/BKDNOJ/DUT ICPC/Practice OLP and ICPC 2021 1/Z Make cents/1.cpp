#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int c,n;
        cin >> c >> n;
        unordered_map<string,double>d;
        d["JD"] = 1;
        string s;
        double res = 0;
        double point = 0;

        for (int i = 1; i <= c; i++) {
                cin >> s;
                cin >> d[s];
        }
        for (int i = 1; i <= n; i++) {
            cin >> point;    
            cin >> s;
            res += (d[s]*point);
        }

        cout << fixed << setprecision(6) << res << endl;
        d.clear();
    }
    return 0;
}