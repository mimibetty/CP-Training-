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

int a[105];

int main() {
    freopen("input.txt", "r", stdin);       
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >>t;
    for (int q = 1; q <= t; q++) {
        int n;
        int res =0;
        int minval = INF;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            minval = min(minval,a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] > minval) res++;
        }
        cout << res <<endl;
    }
    return 0;
}
