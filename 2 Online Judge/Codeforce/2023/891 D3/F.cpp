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
    int n;
    cin >> n;
    map<ll,ll>d;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        d[a]++;
    }
    int t;
    cin >> t;
    vector<ll>res;
    for (int z = 1; z <= t; z++) {
        ll x,y;
        cin >> x >> y;
        ll delta = x*x - 4*y;
        if (delta < 0) {
            res.pb(0);
        }
        else if (delta == 0) {
            if(x % 2 != 0) {
                res.pb(0);
            }
            else {
                x/=2;
                ll z = d[x] *(d[x]-1)/2;
                res.pb(z);
            }
        }
        else {
            ll z = sqrt(delta);
            ll val = -1;
            bool ok = 0;
            for (ll i = -2;i <= 2; i++) {
                if ((z+i) * (z+i) == delta) {
                     ok = 1;
                     val = z+i;   
                }
            }

            if (ok == 0) {
                res.pb(0);
            }
            else{
                if ((x + val) % 2 != 0) {
                    res.pb(0);
                }
                else {
                    long long x1 = (x + val)/2;
                    long long x2 = x - x1;
                    ll tmp = d[x1] * d[x2];
                    res.pb(tmp);                
                }
            }
        }
    } 
    for (auto i : res) cout << i << ' ';
    cout << endl;
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
    while (t--)    
    solve();
    
    return 0;
}