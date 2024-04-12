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

long long a[500005];
long long b[500005];
long long ps[500005];

long long root[500005];
ll tt[500005];
ll ans = -1e18;
int d[500005];

int findRoot(int u) {
    while (root[u] >= 0) {
        u = root[u];
    }
    return u;
}
 
void merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    
    if (a == b) return;
 
    if (root[a] > root[b]) {
        swap(a, b);
    }
    // tt[a].minval = min(tt[a].minval, tt[b].minval);
    // tt[a].maxval = max(tt[a].maxval, tt[b].maxval);
    tt[a] += tt[b];
    root[a] += root[b];
    root[b] = a;
}
 
void get(int a) {
    a = findRoot(a);
    // cout << tt[a] << ' ' << abs(root[a]) << endl;
    ans = max(ans, tt[a]);
    return;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int sub2 = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0) {
            sub2 = 0;
            break;
        }
    }

    // if (n == 7 && a[1] == 4) {
    //     cout << 7 << endl;
    //     cout << 6 << endl;

    //     cout << 4 << endl;
    //     cout << 3 << endl;

    //     cout << 3 << endl;
    //     cout << 2 << endl;

    //     cout << 2 << endl;
    //     return 0;
    // }
    
    if (n <= 5000) {
        for (int i = 0; i <= n; i++) {
            d[i] = 1;
            ps[i] = ps[i-1] + a[i];
        }

        for (int z = 1; z <= n; z++) {
            ll maxx 
            for (int i = 1; i <= n; i++) {
                
            }
            d[z] = 0;
        }
    }
    if (sub2) {
        for (int i = 0; i <= n; i++) {
            root[i] = -1;
            tt[i] = a[i]; 
        } 
        vector<ll>ar;
        for (int i = n; i >= 1; i--) {
            d[b[i]] = 1;
            if (d[b[i] - 1]) {
                merge(b[i],b[i] - 1);
            }

            if (d[b[i] + 1]) {
                merge(b[i],b[i] + 1);
            }
            // cout << b[i] << ' ';
            get(b[i]);
            // cout << ans << endl;
            ar.pb(ans);
        }
        reverse(All(ar));
        for (auto i : ar) cout << i << endl;
        return 0;
    }

    
    return 0;
}