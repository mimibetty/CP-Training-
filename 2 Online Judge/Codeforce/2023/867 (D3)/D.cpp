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

ll a[200005];
ll n;

void solve() {
    
    cin >> n;
    if (n == 1) {
        cout << 1 <<endl;
        return;
    }
    if (n % 2 != 0) {
        cout << -1 <<endl;
        return;
    }

    int x = n;
    int y = 1;
    ll s = 0;
    vector<int>z;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            cout << x << ' ';
            x -= 2;
            a[i] = x;
            s += x; 
        }
        else {
            cout << y << ' ';
            y += 2;
            a[i] = y;
            s += y;
        }
        // z.pb(s%n+1);
    }
    cout <<endl;
    // for (auto i : z) cout << i << ' ';
    //         cout <<endl;

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