#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

bool snt(int n) {
    if (n <= 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return 0;

    return 1;
}

int cnt[20];

int main() {
     //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i <= 9; i++) cnt[i] = 0;
        //cout << t << "START" << endl;
        int n;
        string s;
        cin >> n;
        cin >> s;

        bool ok = 0;

        for (int i = 0; i < n; i++) {
            int a = s[i] - '0';
            cnt[a]++;
        } 

        for (int i = 4; i <= 9; i++) {
            if (snt(i) == 0 && cnt[i] > 0) {
                cout << 1 << endl;
                cout << i << endl;
                ok = 1;
                break;
            }
        }
        if (ok == 1) continue;

        if (cnt[1] >= 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            ok = 1;
        }
        if (ok == 1) continue;

        
        for (int i = 2; i <= 9; i++) {
            if (cnt[i] >= 2) {
                cout << 2 << endl;
                cout <<i*11 << endl;
                ok = 1;
                break;                
            }
        }
        if (ok == 1) continue;

        vector<int>b = {2,3,5,7};
        int vt2 = 0, vt5 = 0;

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '2' && vt2 == 0) vt2 = i;
            if (s[i] == '5' && vt5 == 0) vt5 = i;
            if (vt2 != 0 && vt5 != 0) break;
        }

        if (vt2 != 0) {
            cout << 2 << endl;
            cout << s[0] << 2 <<endl;
            ok = 1;
        }
        if (ok == 1) continue;

        if (vt5 != 0) {
            cout << 2 << endl;
            cout << s[0] << 5 <<endl;
            ok = 1;
        }
        if (ok == 1) continue;

        bool done = 0;
        int num;
        for (auto i : b) {
            if (done == 1) break;

            int vt = 1e9;
            for (int j = 0; j < n; j++) {
                num = s[j] -'0';
                if (num == i) {
                    vt = j;
                    break;
                }
            }
            for (int j = vt+1; j < n; j++) {
                num = i*10 + (s[j] - '0');
                if (snt(num) == 0) {
                    cout << 2 << endl;
                    cout << num << endl;
                    done = 1;
                    break;
                }
            }
        }
    }
    return 0;
}