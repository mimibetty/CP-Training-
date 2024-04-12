#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
int a[200005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int maxval = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i < n; i++) {
        maxval = max(maxval,a[i]); 
    }

    if (a[2] - a[1] >= 2 || maxval > a[n] || a[n] - a[1] > (n-1)) {
        cout << "impossible";
        return 0;
    }

    cout << a[1] << ' ';
    int num = a[1];
    for (int i = 2; i < n; i++) {
        if (num < a[n]) num++;
        cout << num << ' ';
    }
    cout << a[n];   
    return 0;
}