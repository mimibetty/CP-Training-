#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int cnt[1000005];
int x[1000005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }    

    for (int i = 1; i <= 1e6; i++) {
        for (int j = 1; j*i <= 1e6; j++) {
            x[i] += cnt[i*j];
        }
    }

    for (int i = 1e6; i >= 1; i--) {
        if (cnt[i] >= 2) {
            cout << i;
            return 0;
        }
    }
    return 0;
}