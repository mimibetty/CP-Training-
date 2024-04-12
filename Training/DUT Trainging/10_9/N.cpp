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
map<long long, pair<int,int>>d;
map<long long,bool>vs;

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
        if (d[a[i]].fi == 0) {
            d[a[i]].fi = i;
        } 
        d[a[i]].se = i;
        vs[a[i]] = 1;
    }

    int t;
    cin >> t;
    long long cur = 0;
    while (t--) {
        char q;
        long long z;
        cin >> q >> z;
        if (q == '?') {
            if (vs[z] == 0) {
                cout << -1 << endl;
            }
            else {
                // for (int qq = 1; qq <= n; qq++) {
                //     long long z1 = (d[a[qq]].fi + cur - 1) % n + 1;
                //     long long z2 = (d[a[qq]].se + cur - 1) % n + 1;
                //     cout << z1 << ' ' << z2 << endl;
                    // if (z12 > z22) {
                    //     cout << 1 << " ";
                    // }
                    // else cout << z12 <<" ";    
                // }
                // cout << endl;
                long long l = d[z].fi;
                long long r = d[z].se;
                long long z1 = (l + cur - 1) % n + 1;
                long long z2 = (r + cur - 1) % n + 1;
                // cout << z1 << ' ' << z2 << endl;
                if (z1 > z2) {
                    cout << 1 << endl;
                }
                else cout << z1 <<endl;
                // cout << endl;
            }
        }
        else {
            cur += z;
            cur %= n;
            if (cur < 0) {
                cur += n;
            }
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
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}