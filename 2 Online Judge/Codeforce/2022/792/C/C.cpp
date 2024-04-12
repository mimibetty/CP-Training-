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

long long x[200005];
void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>>a;
    a.resize(n+2);
    for (int i = 0; i <= n+1; i++) a[i].resize(m+2);

    vector<vector<int>>b;
    b.resize(n+2);
    for (int i = 0; i <= n+1; i++) b[i].resize(m+2);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; 
            b[i][j] = a[i][j];  
        } 
    }

    for (int i = 1; i <= n; i++) {
        sort(b[i].begin() + 1 , b[i].end() - 1);
    }

    set<int>s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= m ; j++)  {
            if (b[i][j] != a[i][j]) {
                s.insert(j);
            }
        }
    }

    if (s.size() == 0) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    if (s.size() == 2) {
        vector<int>d;
        for (auto i : s) d.pb(i);

        for (int i = 1; i <= n; i++) {
            swap(a[i][d[0]], a[i][d[1]]);
        }

        
        for (int i = 1; i <= n; i++) {
            for (int j = 1;  j <= m ; j++)  {
                if (b[i][j] != a[i][j]) {
                    cout << -1 << endl;
                    return;
                }
            }
        }

        cout << d[0] << ' ' << d[1] <<endl;
        return;
    }

    cout << -1 << endl;
    return;
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