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

pair<int,int>a[200005];
bool x[200005];
void solve() {
    string s;
    cin >> s;
    long long m;
    cin >> m;
    ll sum = 0;

    int n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        int x = s[i] - 'a' + 1;
        a[i] = {x,i};
        sum += x;
    }
    if (sum <= m) {
        for (int i = 1; i <= n; i++) cout << s[i];
        cout << endl;
    }
    else {
        sort(a+1,a+1+n);
        // for (int i = 1; i <= n; i++) {
        //     cout << a[i].fi << ' ' << a[i].se << endl;
        // }
        int vt = n;
        // cout << endl;
        while (sum > m) {
            // cout << sum << ' ' << vt << endl;
            sum -= a[vt].fi;
            x[a[vt].se] = 1;
            vt--;
        }
        // cout << sum << endl;
        for (int i = 1; i <= n; i++) if(x[i] == 0) cout << s[i];
            cout << endl;

        for (int i = 1; i <= n; i++) x[i] = 0;
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
    cin >> t;
    while (t--) {
        solve();
        // cout << endl;
    }
    return 0;
}