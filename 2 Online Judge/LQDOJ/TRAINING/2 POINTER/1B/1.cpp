#include<bits/stdc++.h>
using namespace std;

long long a[100005];
long long b[100005];
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    a[n+1] = 1e10;
    n++;
    int vt1 = 1, vt2 = 1;
    while (vt1 <= n && vt2 <= m) {

        if (b[vt2] > a[vt1]) {
            vt1++;
        }
        else {
            cout << vt1-1 << ' ';
            vt2++;
        }
       //  cout << vt1 << ' ' << vt2 << endl;
    }
    return 0;
}


