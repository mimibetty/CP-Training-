#include<bits/stdc++.h>
using namespace std;

long long a[105][105];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << abs(x1-x2) + abs(y1-y2);
        cout << '\n'; 
    }
    return 0;
}
