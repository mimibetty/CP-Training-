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

pair<int,int> a[100005];
int n;

double done(double x) {
    double res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, abs(a[i].fi - x) + a[i].se);
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].fi << ' ';// << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].se << ' ';// << endl;
    // }
    // cout << endl;
    // cout <<endl;

    double p1 = 999999999999;
    double l = a[1].fi, r = a[n].fi;
    double mid;
    
    for (int i = 1; i <= 100; i++) {
        mid = 1.0000000*(l+r)/2;
        if (done(mid) <= p1) {
            p1 = done(mid);
            r = mid;
        }
        else {
            l = mid;
        }
        // cout << done(mid) << ' ' << mid << ' ' << l << ' ' << r << endl;
    }

    // cout << endl << endl << endl;
    
    double p2 = 999999999999;
    double l2 = a[1].fi, r2 = a[n].fi;
    for (int i = 1; i <= 100; i++) {
        mid = 1.0000000*(l2+r2)/2;
        if (done(mid) <= p2) {
            p2 = done(mid);
            l2 = mid;
        }
        else {
            r2 = mid;
        }
        // cout << done(mid) << ' ' << mid << ' ' << l2 << ' ' << r2 << endl;

    }
    precision(7);
    if (p1 < p2) cout << l <<endl;
    else cout << l2 << endl;
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