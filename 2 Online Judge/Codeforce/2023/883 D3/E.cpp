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

map<unsigned long long, bool>cnt;
void solve() {
    ll n;
    cin >> n;
    ll x = sqrt(n);
    for (int i = -100; i <= 100; i++) {
        ll z = x + i;
        if (z < 2) continue;
        ll c = z*z + z + 1;
        if (c == n) {
            cout << "YES" << endl;
            return;
        }
    }
    if (cnt[n]) cout << "YES" << endl;
    else cout << "NO" <<endl;
    // n = (q^x - 1)/(q - 1)
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    unsigned long long limm = 1e18;
    for (int i = 2; i <= 1000000; i++) {
        unsigned long long  qx = 1, s = 1;
        for (int j = 1; j <= 30000; j++) {
            qx *= i;
            s += qx;
            if (s > limm) {
                break;
            }
            if (j > 1) cnt[s] = 1;
        }
    }
    // for (int i = 1; i <= 300; i++) {
    //     if (cnt[i]) cout << i << " ";
    // }
    int t;
    cin >> t;
    while (t--)
    solve();
    
    return 0;
}