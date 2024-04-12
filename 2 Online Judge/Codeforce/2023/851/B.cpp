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

void solve() {
    ll n;
    cin >> n;

}
bool ok (int x, int y) {
    int tong1 = 0, tong2 = 0;
    while (x > 0) {
        tong1 += (x%10);
        x /= 10;
    }
    while (y > 0) {
        tong2 += (y%10);
        y /= 10;
    }
    return (abs(tong2 - tong1) <= 1);
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // for (int n = 19; n <= 1000; n+=20) {
        int n = 1999;
        int z = n/2;
        int res = 1e9;

        for (int i = n; i >= 1; i--) {
            int x = i;
            int y = n - i;
            if (ok(x,y)) {
              if(abs(z - x) <= res) {
                res = x;
              }
            if(abs(z - y) <= res) {
                res = y;
              }
              
              cout <<n << ' ' << x << " " << y << endl;  
              // break;
            } 
        }
        cout <<n << ' ' << z << ' ' << res <<endl;

    // }


    // cout << 199/2;
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    return 0;
}