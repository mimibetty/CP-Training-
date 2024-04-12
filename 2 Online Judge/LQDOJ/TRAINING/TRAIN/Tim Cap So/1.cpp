#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim6 = 1e6 + 5;
int a[lim6];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    bool done = 0;
    map<int,int>d,vt;
    int n,x;
    cin >> n >> x;

    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
        d[a[i]]++;
        vt[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (x - a[i] >= 0) {
            if (d[a[i]] > 0 && d[x-a[i]] > 0 && (x - a[i]) != a[i]) {
                cout << vt[a[i]] << ' '<< vt[x- a[i]] << endl;
                d[a[i]] = 0;
                d[x- a[i]] = 0;
                done = 1;
            }    
        }
    }

    if (done == 0) cout << "No solution";
    
    return 0;
}