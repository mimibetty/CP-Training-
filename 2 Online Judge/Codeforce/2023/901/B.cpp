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

ll a[100], b[100];
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= m; i++) cin >> b[i];
        
    if (k % 2 == 0) {
        k = min(k, 1000);
    }
    else k = min(k,999);

    for (int i = 1; i <= k; i++) {
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);

        if (i % 2 == 1) {
            if (a[1] < b[m])            swap(a[1],b[m]);
        }
        else {
            if (b[1] < a[n]) swap(b[1], a[n]);
        }

    }
    ll res =0;
    for (int i = 1; i <= n; i++) {
            res += a[i];
    }
    cout << res <<endl;
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