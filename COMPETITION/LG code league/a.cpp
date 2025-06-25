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

long long n,x,y,z;
long long a[1005];
double b[1005];
bool check_(long long f) {
    if (x - f < 0) return 1;
    for (int i = 1; i < n; i++) {
        b[i] = 1.0000000*x/a[i];
    }
    b[n] = 1.0000000*(x-f)/a[n];
    b[n]++;

    // for (int i = 1; i <= n; i++) {
    //     b[i] = int(b[i]);
    // }
        // cout << "TEST  " << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << b[i] << ' ';
        // }
        // cout << endl;
    double lim = b[n];
    // cout << "lim " << lim << endl;
    bool ok = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] <= lim) {
            ok = 0;
            break;
        }
    }
    return ok;
}
void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll z = check_(y);

    if (check_(y) == 0) {
        cout << -1 << endl;
        return;
    }

    ll maxval = 0;
    for (int i = 1; i <= n; i++) {
        maxval = max(a[i], maxval);
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxval) cnt++;
    }
    if (a[n] == maxval && cnt == 1) {
        cout << 0 << endl;
        return;
    }


    long long l = 0, r = y;
    long long ans = 0;
    while (l < r) {
        long long mid = (l+r)/2;
        // cout <<"CHECK  " << l << ' ' << r << ' '<< mid << "  " << check_(mid)<< endl;
        if (check_(mid)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    if (check_(l) == 0) {
        cout << -1 << endl;
        return;
    }
    cout << l << endl;
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