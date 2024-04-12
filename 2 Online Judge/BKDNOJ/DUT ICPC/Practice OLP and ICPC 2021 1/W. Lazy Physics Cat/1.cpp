#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const double pi = acos(-1);

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
        int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        double res = 0;
        double x = pi*b/360;
        res = (b*a*a*pi/360) - (a*a*sin(x)*cos(x));
        cout << setprecision(6) << fixed << res << endl;
    }
    return 0;
}