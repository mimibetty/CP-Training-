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

char a[40];
int vs[45];
int sf[200005];
void solve() {
    int n;
    string s;
    int k;
    cin >> n >> s >> k;


    for (int i = 0; i <= 40; i++) vs[i] = 0;

    for (int i = 1; i <= k; i++) {
        cin >>a[i];
        vs[a[i] - 'a'] = 1;
        // cout << a[i];
    }
 
    // sf[n-1] = 0;    
    for (int i = 0 ; i <= n; i++) sf[i] = 0;
    for (int i = n - 2; i >= 0 ; i--) {
        if (vs[s[i+1] - 'a'] == 1) sf[i] = 1;
        else if (sf[i+1] > 0) sf[i] = sf[i+1] + 1;
    }

    int res = 0;
    for (int i = 0; i < n; i++) res = max(res , sf[i]);
        cout << res << endl;

    for (int i = 0; i < n; i++) sf[i] = 0;
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