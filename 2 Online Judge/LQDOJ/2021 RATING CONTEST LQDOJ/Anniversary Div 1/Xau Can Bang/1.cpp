#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

bool cnt1[200];
bool cnt2[200];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        bool check = 1;
        int n = s.size();

        if (n % 2 != 0) check = 0;

        for (int i = 0; i < n; i++) {
            if (i < (n/2)) cnt1[s[i]] = 1;
            else cnt2[s[i]] = 1;
        }

        for (char i = 'a'; i <= 'z'; i++) {
            if (cnt2[i] != cnt1[i]) {
                check = 0;
                break;
            }
        }
        if (check == 1) cout << "YES";
        else cout << "NO" ;
        cout << endl;

        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
    }

    return 0;
}