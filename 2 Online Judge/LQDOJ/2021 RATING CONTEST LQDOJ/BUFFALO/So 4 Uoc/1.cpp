#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,res = 0;
    cin >> n;
    int can = sqrt(n);
    set<int>s;
    for (int i = 1; i <= can; i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert(n/i);
        }
    }
    for (auto i : s) {
        int cani = sqrt(i);
        int cnt = 0;
        for (int j = 1; j <= cani; j++) {
            if (i % j == 0) cnt += 2;
        }
        if (cani * cani == i) cnt--;
        if (cnt == 4) res++;
    }
    cout << res;
    return 0;
}