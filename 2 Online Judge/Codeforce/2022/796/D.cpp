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
long long ps[200005];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int z = 1; z <= t ;z++) {
        ll n,k;
        cin >> n>> k;
        for (int i = 1;  i <= n; i++) {
            cin >> a[i];
            ps[i] = ps[i-1] + a[i];
        }

            ll res = 0;
        if (k <= n) {
            for (int i = k; i <= n; i++) {
                res = max(res, ps[i] - ps[i-k]);
            }
            k--;
            res += (k+1)*(k)/2;
            cout << res <<endl;
            // cout << z << ' ' << res <<endl;
        }
        else {
            res =  ps[n] + k*n - n*n + ((n-1) * n / 2);
            cout << res <<endl;
            // res += ps[n];

            // n--;
            // res += (n+1)*(n)/2;
            // n++;

            // // cout << res <<endl;
            
            // k -= n;

            // long long ex = k / n;
            // long long gg = ex * (n + 1) * n /2;

            // k %= n;

            // long long gg2 = (k+1) * k / 2;
            // res += gg + gg2;
            // cout << res << endl;
        } 
        for(int i = 1; i <= n; i++) ps[i] = 0;
    }
    return 0;
}