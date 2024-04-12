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

int a[200005];
void solve() {
    int n,x,y;
    cin >> n >> x >> y;;
    map<pii, int>d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[{a[i]%x, a[i]%y}]++;
    }
    ll f = 0;
    for (int i = 1; i <= n; i++) {
        d[{a[i]%x, a[i]%y}]--;
        int xx, yy;
        if (a[i]%x == 0) {
            xx = 0;
        }
        else {
            xx = x - a[i]%x;
        }

        if (a[i]%y == 0) {
            yy = 0;
        }
        else {
            yy = a[i]%y;
        }

        f += d[{xx,  yy}];
    }
    cout << f << endl;
    d.clear();
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