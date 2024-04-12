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

long long a[100005], b[100005];
long long f[35];
vector<int>c[32];
const int limm = 1e9;
void solve() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++) {
        cin >> b[i];
        c[b[i]].pb(i);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) continue;

        int cnt = 0;
        long long x = a[i];
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }
        int vt = 0;
        while (cnt >= 1) {
            int vtnew = limm;
            for (int j = 1; j <= min(30, cnt); j++) {
                if (c[j].size() > 0) {
                    auto it = lower_bound(c[j].begin(), c[j].end(), vt);
                    if (it != c[j].end()) vtnew = min(vtnew, *it); 
                }
            }
            
            if (vtnew == limm) {
                break;
            }
            else {
                a[i] += f[b[vtnew] - 1];
                vt = vtnew;
                cnt = 0;
                x = a[i];
                while (x % 2 == 0) {
                    x /= 2;
                    cnt++;
                }       
            }
        }

    }
    // for (int i = 1; i <= q; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (a[j] % f[b[i]] == 0) {
    //             // cout << a[j] << ' ' << i << endl;
    //             a[j] += f[b[i] - 1];
    //         }
    //     }
    // }
    for (int i = 1; i <= 30; i++) c[i].clear();
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    EL;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    f[0] = 1;
    for (int i = 1; i <= 30; i++) {
        f[i] = f[i-1] * 2;
        // cout << i << ' ' << f[i] << endl;
    }
    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}