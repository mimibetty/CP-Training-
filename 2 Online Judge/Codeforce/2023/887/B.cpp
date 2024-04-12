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
int vt = 0;
pair<ll,ll>p[1005];
void solve() {
    ll n,k;
    cin >> n >> k;
    if (k > vt) {
        if (n == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    else {
        ll x = p[k].fi;
        ll y = p[k].se;
        // cout << x << ' ' << y << endl;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            ll a = i;
            ll b = (n - x*a)/y;
            // cout << a << ' ' << b <<' ' << a*x + b*y <<  endl;
            if (a > b) break;
            if (a*x + b*y == n) {
                res++;
                // cout << a << ' ' << b << endl;
            }
        }
        cout << res << endl;
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    p[1] = {1,0};
    p[2] = {0,1};
    p[3] = {1,1};
    p[4] = {1,2};
    p[5] = {2,3};
    p[6] = {3,5};
    int xx = 200005;
    for (int i = 7; i <= 1000; i++) {
        p[i].fi = p[i-1].se;
        p[i].se = p[i-1].fi + p[i-1].se;
        if (p[i].fi > xx) {
            vt = i-1;
            break;
        }
    }
    int t;
    cin >> t;
    while (t--)   
    solve();
    return 0;
}