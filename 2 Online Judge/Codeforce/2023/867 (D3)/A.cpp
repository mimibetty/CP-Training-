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

int a[1000];

int b[1000];
void solve() {
    int n,t;
    cin >> n >> t;
    for (int  i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int  i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int res = -1;
    int vt = -1;
    for (int i = 1; i <= n; i++) {
        if (i-1 + a[i] <= t && res < b[i]) {
            res = max(res, b[i]);
            vt = i;
        }
    }
    cout <<vt <<endl;
    // cout <<vt << ' ' << res <<endl;
    return;
    
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}