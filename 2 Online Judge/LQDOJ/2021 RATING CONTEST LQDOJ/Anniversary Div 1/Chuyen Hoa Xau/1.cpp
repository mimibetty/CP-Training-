#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
char a[10] = {'u','e','o','a','i'};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
    
        for (int i = 0; i < s.size(); i++) {
            bool check = 0;
            for (int j = 0; j < 5; j++) {
                if (s[i] == a[j] || (s[i] + 32) == a[j]) {
                    check = 1;
                    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
                    break;
                }
            }
            if (check == 0) {
                if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
            }
        }

        cout << s << endl;
    }
    return 0;
}