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

long long n,x,y;
long long a[1005];

bool check_(long long z) {
    double my_time;
    if (z >= x) {
        my_time = (double)x / z;
    } else {
        my_time = 1.0 + (double)(x - z) / a[n];
    }
    
    for (int i = 1; i < n; i++) {
        double other_time = (double)x / a[i];
        if (my_time >= other_time) {
            return false;
        }

        long long mine = (x-z)*a[i];
        long long yours = x*a[n];
        if (mine >= yours) {
            return false;
        }        
    }
    return true;
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (!check_(y)) {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (a[i] >= x) {
            cout << -1 << endl;
            return;
        }
    }

    double my_time_no_booster = (double)x / a[n];
    bool can_win_without_booster = true;
    for (int i = 1; i < n; i++) {
        double other_time = (double)x / a[i];
        if (my_time_no_booster >= other_time) {
            can_win_without_booster = false;
            break;
        }
    }
    
    if (can_win_without_booster) {
        cout << 0 << endl;
        return;
    }

    long long l = 1, r = y;
    long long ans = y;
    
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check_(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
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
