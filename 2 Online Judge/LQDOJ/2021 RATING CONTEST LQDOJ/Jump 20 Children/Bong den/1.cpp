#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5 + 5;

bool a[lim5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            a[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j+=i) {
                if (a[j] == 1) a[j] = 0;
                else a[j] = 1;
            }
        }
        cout << a[n] <<endl;;
    }   
    return 0;
}