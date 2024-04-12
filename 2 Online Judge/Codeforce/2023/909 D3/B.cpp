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

long long a[200005];
long long ps[200005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
  
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + a[i];
    }

    ll res = 0;

    // for (int i = 1; i < n; i++) {
    //     res = min()
    // }
    ll maxx = 0,minn = 1e9;
    for (int i = 1; i <= n; i++) {
        maxx = max(a[i], maxx);
        minn = min(a[i], minn);
    }
    res = maxx - minn;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int x1 = i;
            vector<long long>f;
            for (int j = x1; j <= n; j+=x1) {
                long long z = ps[j] - ps[j - x1];
                f.pb(z);
            }            
            long long tmp1 = 1e18;
            sort(All(f));
            // cout << x1 << endl;
            // for (auto j : f) cout << j << ' ';
            // EL;
            // for (int j = 1; j < f.size(); j++) {
            //     tmp1 = min(tmp1, 1ll*abs(f[j] - f[j-1]));
            // }
            res = max(res , 1ll* f[f.size()-1] - f[0]);
            

            int x2 = n/i;
            vector<long long>f2;
            for (int j = x2; j <= n; j+=x2) {
                long long z = ps[j] - ps[j - x2];
                f2.pb(z);
            }            

            sort(All(f2));
            // cout << x2 << endl;
            // for (auto j : f2) cout << j << ' ';
            // EL;
            // ll tmp2 = 1e18;
            // for (int j = 1; j < f2.size(); j++) {
            //     tmp2 = min(tmp2, 1ll*abs(f2[j] - f2[j-1]));
            // }
            res = max(res , 1ll* f2[f2.size()-1] - f2[0]);
        }   
    } 

    cout << res << endl;
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