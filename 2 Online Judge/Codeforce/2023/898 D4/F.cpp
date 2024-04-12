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
long long h[200005];
int group[200005];
ll ps[200005];
void solve() {
    long long n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int x = 1;
    group[1] = 1; 
    ps[1] = a[1];
    for (int i = 2 ; i <= n; i++) {
        if (h[i-1] % h[i] == 0) {
            group[i] = group[i-1];
        }
        else {
            x++;
            group[i] = x;
        }
        ps[i] = ps[i-1] + a[i];
    }
    int res = 0;
    int vt = 1;
    for (int i = 1; i <= n; i++) {
        vt = max(vt,i);
        while (vt+1 <= n && group[vt+1] == group[i] && 1ll*ps[vt + 1] - ps[i-1] <= k) {
            vt++;
            res = max(res, vt-i+1);
        }
        ll s = ps[vt] - ps[i-1];
        if (s <=k) {
            res = max(res, vt-i+1);
        }
        // cout << i << ' ' << vt << ' ' << ps[vt] - ps[i-1] << ' ' <<res << endl; 
    }
    cout << res <<endl;
    // EL;
    // EL;
    // cout << "GRTR" << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << group[i] << ' ';
    // }
    // EL;
    // for (int i = 1; i <= n; i++) {
    //     cout << ps[i] << ' ';
    // }
    // EL;
    // EL;

    for (int i = 1; i <= n; i++) {
        group[i] = ps[i] = 0;
    }
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