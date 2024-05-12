/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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
    long long r;
    cin >> r;
    if (r == 1) {
        cout << 8 << endl;
        return;
    }

    ll res = 0; 
    ll vt = -1e9;
    for (ll i = -r; i <= r; i++) {
        long long x = i;
        if (r < x) continue;
        
        long long z = r*r - x*x;
        long long sq1 = sqrt(z);
        ll z2 = (r + 1)*(r + 1) - x*x;
        ll sq2 = sqrt(z2);
        if (sq2 * sq2 == z2) sq2--;
        ll tmp = res;
        // cout << sq1 << ' ' << sq2<< ' ';
        // cout <<endl;
        res += max(1ll*0, 2*(sq2 - sq1 + 1)); 
        if (1ll * r * r <= 1ll*x*x*2 and 1ll * x * x * 2 < 1ll*(r+1)*(r+1)) {
            res -= 1;
        }
        if (res > 0) {
            cout << i << ' ' << res << ' ';
            // cout << res * 2 + 2*abs(i - 1)  << endl;;
            
            cout << endl;
            cout <<"Stt  "  << i << ' ' << res  << endl;;           
            res = res*2 + 2*(abs(i) + 1);
             
            cout << "RES" << res << endl;
            return;
        }
        // cout <<"Stt  "  << i << ' ' << res - tmp  << " " << res << endl;;           
    }
    cout << "ERR  ";
    cout << res << endl ;

}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
 cin >> t;
    while (t--)    
    solve();
    
    return 0;
}