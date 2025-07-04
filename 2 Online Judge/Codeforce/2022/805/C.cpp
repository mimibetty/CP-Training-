#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

long long a[200005];
void solve () {
    int n,k;
    cin >> n >> k;
    map<long long,int>dmax;
    map<long long,int>dmin;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dmax[a[i]] = max(dmax[a[i]],i);
        if (dmin[a[i]] == 0) dmin[a[i]] = i;
        else dmin[a[i]] = min(dmin[a[i]],i);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ' << dmin[a[i]] << ' '<<dmax[a[i]] << endl;
    // }
    for (int z = 1; z <= k ;z++) {
            int u,v;
            cin >> u >> v;

            if (dmin[u] == 0 || dmin[v] == 0) {
                cout << "no" << endl;
            }
            else {
                if (dmin[u] < dmax[v]) {
                    cout << "yes" << endl;
                }
                else cout <<"no" << endl;
            }
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
    while (t--) {
        solve();
    }
    return 0;
}