#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

char a[12] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X','Y'} ;
bool cnt[200];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (int i = 0; i < 11; i++) cnt[a[i]] = 1;
    
    int t;
    cin >> t;

    while(t--) {
        bool ok = 1;
        string s;
        cin >> s;
        int n = s.size();
        if (n % 2 == 0) n/=2;
        else {
            n/=2;
            n++;
        }

        for (int i = 0 ; i < n; i++) {
            if (s[i] != s[s.size()-1-i] || cnt[s[i]] == 0) {
                ok = 0;
                break;
            }
        }

        if (ok == 1) cout << "yes";
        else cout << "no";
        cout << endl;
    }

    return 0;
}