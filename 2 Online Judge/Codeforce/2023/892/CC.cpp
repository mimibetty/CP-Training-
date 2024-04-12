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
int a[6];
 long long chose = 7;
void solve() {
    int n;
    cin >> n;
    // if (n == 2) {
    //     cout << 2 << endl;
    //     return ;
    // }
    // if (n == 3) {
    //     cout << 7 << endl;
    //     return;
    // }

    // if (n == 4) {
    //     cout << 17 << endl;
    //     return;
    // }
    
    ll sum = 0;
    ll mx = -1e18;
    chose = n;
    for  (int i = 1; i <= chose; i++) a[i] = i-1;
    do {
        ll s = 0;
        ll maxx = 0;
        for (int i = 1;i <= chose; i++) {
            s += (n-i+1)*(n-a[i]);
            // cout << n-i+1 << ' ' << n-a[i] << endl;;
            maxx = max(maxx,1ll*(n-i+1)*(n-a[i]));
        }
        // EL;
        s-= maxx;
        mx = max(mx, s);
        // for (int  i = 1; i <= 4; i++) cout << a[i] << ' ';
        // cout << endl;

    } while(next_permutation(a + 1, a + 1 + chose) );

    do {
        ll s = 0;
        ll maxx = 0;
        for (int i = 1;i <= chose; i++) {
            s += (n-i+1)*(n-a[i]);
            // vt lon den be
            // gia tri 
            // cout << n-i+1 << ' ' << n-a[i] << endl;;
            maxx = max(maxx,1ll*(n-i+1)*(n-a[i]));
        }
        // EL;
        s-= maxx;
        if (s == mx) {
            for (int i = 1; i <= chose; i++) {
                cout << n-i+1 << ' ' << n-a[i] << endl;;
            }
            EL; 
        }

    } while(next_permutation(a + 1, a + 1 + chose) );
    EL;
    EL;
    
    cout << sum + mx << endl;
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