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

long long kk[40];
int checkk(long long n, long long m) {
    long long ucln = __gcd(n,m);
    n /= ucln , m /= ucln;
    long long x = 1;
    vector<int>f;
    while (x <= m) {
        f.pb(x);
        x *= 2;
    }
    int lenn = f.size();
    long long z = n;
    long long res = 0;

    long long ok = 1;
    for (int i = lenn - 1; i >= 0; i--) {
        if (z  >= f[i]) {
            z -= f[i];
            ll s = 0;
            ll cnt = 1;
            ll tmp = f[i];
            while (tmp < m) {
                    s+=cnt;
                    cnt *= 2;
                    tmp *= 2;
            }
            if (tmp != m) ok = 0;
            res += f[i] * s;
        }
    }
    return ok;
}
void solve() {
    long long n, m;
    cin >> n >> m;

    n %= m;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    if (checkk(n,m) == 0) {
        cout << -1 <<endl;
        return;  
    } 

    long long ucln = __gcd(n,m);
    n /= ucln , m /= ucln;
    long long x = 1;
    vector<int>f;
    while (x <= m) {
        f.pb(x);
        x *= 2;
    }
    int lenn = f.size();
    long long z = n;
    long long res = 0;

    long long ok = 1;
    for (int i = lenn - 1; i >= 0; i--) {
        if (z  >= f[i]) {
            z -= f[i];
            ll s = 0;
            ll cnt = 1;
            ll tmp = f[i];
            while (tmp < m) {
                    s+=cnt;
                    cnt *= 2;
                    tmp *= 2;
            }
            if (tmp != m) ok = 0;
            res += f[i] * s;
            // cout <<f[i] << ' ' << tmp <<endl;
        }
    }
    cout <<res <<endl;
    // EL;
    // cout << n <<endl;

}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    kk[0] = 1;
    long long f = 1;
    for (int i = 1; i <= 32; i++) {
        f *= 2;
        kk[i] += kk[i-1] + f;
    }

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}