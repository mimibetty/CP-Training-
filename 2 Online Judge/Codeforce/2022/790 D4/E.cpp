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

long long a[2000005];
long long ps[2000005];

void solve() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+1+n);

    for (int i = 1; i <= n; i++) {
        ps[i] = a[i] + ps[i-1];
        // cout << ps[i] << ' ';
    }
    // cout << endl;

    for (int z = 1; z <= q; z++) {
        // cout << z << endl;
        long long x ;
        cin >> x;
        // cout << x << endl;
        if (ps[n] < x) {
            cout << -1 <<endl;
            continue;
        }

        int lower = 1, upper = n;
        int mid;
        while (lower < upper) {
            mid = (lower + upper + 1)/2;
            long long sum = ps[n] - ps[mid - 1];
            if (sum >= x) {
                lower = mid;
            }
            else {
                upper = mid - 1;
            }
            // cout << lower << ' ' << upper << ' ' << mid << ' ' << ps[mid] << ' ' << sum << endl;
        }
        // cout << lower << endl;
        // cout <<endl;
        cout << n - lower + 1 <<endl;

    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}