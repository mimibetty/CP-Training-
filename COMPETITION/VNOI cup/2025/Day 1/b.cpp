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

vector<pair<long long, int>> primeFactorization(long long num) {
    vector<pair<long long, int>> factors;
    for (long long i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            int count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            factors.pb({i, count});
        }
    }
    if (num > 1) {
        factors.pb({num, 1});
    }
    return factors;
}

void solve() {
    long long n, m;
    cin >> n >> m;

    if (n == m) {
        cout << 0 << endl;
        return;
    }
    if ((n == 1 || m == 1) && n != m)     {
        cout << -1 << endl;
        return;
    }
    if (n > m) {
        cout << -1 << endl;
        return ;
    }

    vector<pair<long long, int>> factors_n = primeFactorization(n);
    vector<pair<long long, int>> factors_m = primeFactorization(m);

    if (factors_n.size() != factors_m.size()) {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 0; i < factors_n.size(); i++) {
        if (factors_n[i].fi != factors_m[i].fi) {
            cout << -1 << endl;
            return;
        }
    }
    long long n_new = n;
    vector<long long> ans;
    while (true) {
        long long x = 1;
        for (int i = 0; i < factors_n.size(); i++) {
            if (factors_n[i].se < factors_m[i].se) {
                if (factors_n[i].se * 2 > factors_m[i].se) {
                    x *= pow(factors_n[i].fi, factors_m[i].se - factors_n[i].se); 
                    factors_n[i].se = factors_m[i].se;
                }
                else {
                    x *= pow(factors_n[i].fi, factors_n[i].se);
                    factors_n[i].se *= 2;
                }
            }
        }
        n_new *= x;
        ans.pb(x);
        
        if (n_new == m) {
            cout << ans.size() << " ";
            for (auto i : ans) cout << i << ' ';
            cout << endl;
            return;
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
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}