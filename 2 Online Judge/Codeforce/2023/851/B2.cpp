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
ll p[20];
void solve() {
    ll n;
    cin >> n;
    if (n % 20 == 19) {
        vector<int>a;
        ll z = n;
        while (z > 0) {
            a.pb(z%10);
            z/=10;
        }
        reverse(All(a));
        ll x[3];
        x[0] = 0;
        x[1] = 0;

        int lenn = a.size();
        bool ok = 0;
        for (int i = 0; i < lenn; i++) {
            if (a[i] % 2 == 0) {
                x[0] += a[i]/2 * p[lenn - i - 1];
                x[1] += a[i]/2 * p[lenn - i - 1]; 
            }
            else {
                x[ok] += (a[i]/2 + 1) * p[lenn - i - 1];
                x[1-ok] += a[i]/2 * p[lenn - i - 1]; 
                ok = 1 - ok;
            }
        }
        cout << x[0] << ' ' << x[1] << endl;
    }   
    else {
        cout << n/2 << ' ' << n - (n/2) << endl;
    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    p[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p[i] = p[i-1] * 10;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}