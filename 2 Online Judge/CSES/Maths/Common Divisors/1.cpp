#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int cnt[1000005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++) {
        int a;
        cin >> a;
        for (int i = 1; i <= sqrt(a); i++) {
            if (a % i == 0) {
                if (i * i == a) cnt[i]++;
                else {
                    cnt[i]++; 
                    cnt[a/i]++;  
                } 
            }
        }
    }

    for (int i = 1e6; i >= 1; i--) {
        if (cnt[i] > 1) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}