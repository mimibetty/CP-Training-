/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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


pair<long long, long long> a[200005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long maxX = -1e9, minX = 1e9, maxY = -1e9, minY = 1e9;
    pii val_maxX, val_minX, val_maxY, val_minY; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        // cout << a[i].fi << ' ' << a[i].se <<endl;
         maxX = max(maxX, a[i].se);
         minX = min(minX, a[i].se);

         maxY = max(maxY, a[i].fi);
         minY = min(minY, a[i].fi);
    }

    // cout << maxY << ' ' << minY << ' ' << maxX << ' ' << minX << endl;
    long long res = 1ll* (maxX - minX) * (maxY - minY);
    cout << res << endl;

    return 0;
}