#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<long long, long long> pll;
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

pair<int,int>a[105];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }    
    
    int res = 0;
    int x1 = 0,x2 = 0,x3 = 0,x4 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].fi == 0 && a[i].se >= 0) {
            x1 = max(x1,a[i].se);
        }

        if (a[i].fi == 0 && a[i].se < 0) {
            x2 = max(x2,abs(a[i].se));
        }

        if (a[i].se == 0 && a[i].fi >= 0) {
            x3 = max(x3,a[i].fi);
        }

        if (a[i].se == 0 && a[i].fi < 0) {
            x4 = max(x4,abs(a[i].fi));
        }
    }
    // cout <<x1 << ' ' <<x2 << ' ' <<x3 << ' ' <<x4 << endl;
    cout << 2*(x1 +x2 +x3 +x4) << endl;

}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}