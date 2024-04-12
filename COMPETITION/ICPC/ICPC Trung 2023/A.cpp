/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 const int mod = 1e9+7;
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
vector<ll> p(110);
void solve() {
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=1; i<=n;i++) cin >> a[i];
    vector<int> s(71,0);
    vector<ll> f(71,0);
    for (int i=1; i<=n; i++) {
        for (int j=1; j <= a[i]; j++) {
            if (a[i] % j == 0) {
                s[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i=70; i>=1; i--) {
        ll t = ((p[s[i]]-1) % mod + mod)%mod;

        for (int j= i+1; j<=70; j++) {
            if (j % i == 0) {
                t = ((t - f[j]) % mod + mod) % mod;

            }
        }
        f[i] = t;
        ans = (ans + (t*i)% mod) % mod;
    }
   
    cout << ans << '\n';
}


int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    p[0] = 1;
    for (int i=1; i<=100; i++) {
        p[i] = (p[i-1] * 2) % mod;
    }
    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}