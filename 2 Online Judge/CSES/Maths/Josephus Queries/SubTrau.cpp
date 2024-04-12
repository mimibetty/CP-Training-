#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
bitset<1000000>bs;
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n,k;
        cin >> n >> k;
        int vt = 0;
        int cnt = 0;
        while (bs.count() < k) {
            vt++;
            if (bs[vt] == 0) {
                cnt++;
            } 
            if (cnt == 2) {
                cnt = 0;
                bs[vt] = 1;
            }
            if (vt > n) vt = 1;
        }
        cout  << vt <<endl;
        bs.reset();
    }

    return 0;
}