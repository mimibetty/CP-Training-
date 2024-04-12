#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define cnt_bit __builtin_popcount

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const long long INF = 1e9;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3+5, lim5 = 1e5+5;

int a[lim5];

int main() {
    freopen("input.txt", "r", stdin);       
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >>t;
    set<int>s;
    for (int q = 1; q <= t; q++) {
        int n;
        int am = 0 , duong = 0;
        int num0 = 0;
        int minval = 1e9;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0) num0++;
            if (a[i] > 0) {
                minval = min(minval,a[i]);
                duong++;
            }
            if (a[i] < 0) {
                s.insert(a[i]);
                am++;
            }
        }
        if (num0 > 0) s.insert(0);
        int num = s.size();

        if (duong == 0) cout << am + num0;
        else if (num0 > 0 && duong > 0 && am == 0) cout << max(num0, 2);
        else if (num0 == 0  && am == 0 && duong > 0) cout << 1;
        else if (am > 0 && duong > 0) {
                bool done = 1;
                sort(a + 1, a + 1 + n);
                for (int i = 1; i <= n - 1 ; i++) {
                    if (a[i] <= 0 && a[i+1] <= 0 && a[i] != a[i+1]) {
                        if (abs(a[i]-a[i+1]) < minval) {
                            done = 0;
                            break;
                        }
                    } 
                }
                if (done == 1) cout << max(am + num0, num + 1);
                //else if (done == 1 && num0 == 0) cout << am + 1;    
                //else if (done == 0 && num0 == 0) cout << am;
                else cout << num0 + am;
        }
        cout << endl;
        s.clear();
    }
    return 0;
}
