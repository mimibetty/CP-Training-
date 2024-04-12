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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    long long x = a * b;
    long long z = sqrt(x);
    for (int i = 1; i <= z; i++) {
        if (x % i == 0) {
            long long g = x / i;
            long long h = i;

            ll g1 = g, h1 = h;
            if (g <= a) {
                g1 *= (c/g);
            }
            if (h1 <= b) {
                h1 *= (d/h);
            }
            if (g1 > a && g1 <= c && h1 > b && h1 <= d) {
                cout << g1 << ' ' << h1 << endl;
                return;
            }

            swap(g,h);
            g1 = g, h1 = h;
            if (g <= a) {
                g1 *= (c/g);
            }
            if (h1 <= b) {
                h1 *= (d/h);
            }

            if (g1 > a && g1 <= c && h1 > b && h1 <= d) {
                cout << g1 << ' ' << h1 << endl;
                return;
            }

        }
    }
    cout << -1 << ' ' << -1 <<endl;
    return;
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