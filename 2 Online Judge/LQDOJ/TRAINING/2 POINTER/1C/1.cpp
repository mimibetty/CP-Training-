#include<bits/stdc++.h>
using namespace std;

int a[100005];
long long b[100005];
map<int,int>d;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long res = 0;
    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        res += d[b[i]];
    }

    cout << res;
    return 0;
}



