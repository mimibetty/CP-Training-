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

int n;
long long a[200005];
long long f[200005][32];
long long ps[200005][32];
long long np[31];
bitset<32>bs;
long long x,k;

void resett() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 30; j++) {
            f[i][j] = ps[i][j] = 0;
        }
    }
}
long long check(int mid) {
    int z = mid - x + 1;
    ll s = 0;
    // cout << z <<endl;
    for (int i = 0; i <= 30; i++) {
        if (ps[mid][i] - ps[x-1][i] == z) {
            s += np[i];
        }
    }
    return s;
}
void solve() {
    cin >> n;
    resett();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bs = a[i];
        for (int j = 0; j <= 30; j++) {
            f[i][j] = bs[j];
            // if (bs[j]) cout<< i << ' ' << j << endl; 
        } 
    }
    // EL;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 30; j++) {
            ps[i][j] += ps[i-1][j] + f[i][j];
             // cout << i << ' ' << j << ' ' << ps[i][j] << endl;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> k;
        int l = x, r = n;
        while (l < r) {
            int mid = (l + r + 1)/2;
            if (check(mid) >= k) {
                l = mid;
            }
            else r = mid - 1;
        }
        // cout << l << ' ' << check(l) << endl;
        if (check(l)  < k) cout << -1 << ' ';
        else cout << l << ' ';
    }
    EL;

}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    np[0] = 1;
    long long x = 1;
    int cnt = 0;
    while (x <= 1e9) {
        cnt++;
        x *= 2;
        np[cnt] = x;
    }

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}