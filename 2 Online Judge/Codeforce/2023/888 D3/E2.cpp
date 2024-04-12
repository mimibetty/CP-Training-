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

ll res[200005];
ll a[200005],b[200005];
ll num[200005];
vector<vector<int>>contain;

const ll zzz = 1e18;
ll dp(int x) {
    if (res[x] != zzz) {
        return res[x];
    }
    ll tmp = 0;
    for (auto i :contain[x]) {
        
    }
}
void solve() {
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        res[i] = 1e18;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        res[b[i]] = 0;
    }
    contain.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++) {
            int x;
            cin >> x;
            contain[i].pb(x);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << res[i] << ' ';
    // }
    // EL;
        for (int i = 1; i <= n; i++) {
            // cout << "STT  " << i << endl;
            // cout << res[i] << " ";
            res[i] = min(res[i], a[i]);
            // cout << res[i] << " ";
            ll s = 0;
            if (num[i] != 0) {
                for (auto j : contain[i]) {
                    s += min(res[j], a[j]);
                    // s += a[j];
                }
                res[i] = min(res[i], s);
            }
            // cout << res[i] << " ";
            // cout << "SS   " << s << "    ";
            // EL;
        }
     

    


    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    contain.clear();
    EL;
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