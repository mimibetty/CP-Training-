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

bool vt[200005];
void solve() {
    int n;
    cin >> n;
    vector<ll>odd;
    vector<ll>even;
    ll a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            even.pb(a);
            vt[i] = 1;
        }
        else {
            odd.pb(a);
        }
    }
    sort(All(odd));
    sort(All(even));
    int l = 0, r = 0;
    vector<ll>z;
    for (int i = 1; i <= n; i++) {
        if(vt[i]) {
            z.pb(even[r]);
            // cout << even[r] << ' ';
            r++;
        }
        else {
            z.pb(odd[l]);
            // cout << odd[l] << ' ';
            l++;
        }
    }
    // for (auto i : z) cout << i << " ";
    bool ok = 1;
    for (int i = 0; i < (n-1); i++) {
        if (z[i] > z[i+1]) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        cout << "YES" << endl;
    }
    else cout << "NO" <<endl;
    for (int i = 1; i <= n; i++) vt[i] = 0;

}


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",sdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    solve();
    
    return 0;
}