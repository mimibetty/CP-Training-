/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}
 
// int a[200005];
void solve() {
    ll a,b;
    ll x;
    cin >> x;
    x *= 2;
    a = x * 3 / 4;
    b = x / 4;
    if ((a ^ b) == (a + b) /2 ) cout << a << ' ' << b << endl;
    else cout << "-1" << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // cout << (3|1) << " " << (3 ^ 1) << endl;
    // for (int i = 1; i <= 100; i++) {
    //     int val = i;
    //     bool ok = 0;
    //     cout << i << "   ";
    //     for (int j = 1; j <= 1000; j++) {
    //         if (ok == 1) break;
    //         for (int z = 1; z <= 1000; z++) {
    //             if (j == z) continue;
    //             int f1 = (z ^ j);
    //             int f2 = (z + j) /2;
    //             if ( f1 == f2 && f1 == val) {
    //                 cout << z << ' ' << j << endl;
    //                 ok = 1;
    //             }
    //             if (ok == 1) break;
    //         }
    //     }
    //     if (ok == 0) {cout << "NOOO" << endl;}
    //     cout << endl;
    // }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
