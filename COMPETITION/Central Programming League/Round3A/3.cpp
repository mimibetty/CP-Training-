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
 

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int a[1505][1505];
int dp[1000005];
int vs[1000005];

vector<pair<int,int>>vt[1000005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            vs[a[i][j]] = 1;

            vt[a[i][j]].pb({i,j});
        }
    }
    vector<int>d;
    for (int i = 1; i <= 1000000; i++) {
        if (vs[i] == 1) d.pb(i);
    }
  
    // for (auto i : vt[3]) cout << i.fi << ' ' << i.se << endl;
    // cout << endl;

    int num = d.size();
    for (auto i : d) dp[i] = -9999999;
    dp[a[x][y]] = 0;
    // for (auto i : d) cout << i << ' ' << dp[i] << endl;
    
    for (auto i : d) {
        if (i <= a[x][y]) continue;


        for (auto j : vt[d[i]]) {
            // if (i == 2) cout << j.fi << ' ' << j.se << endl;
            int dx = j.fi - 1;
            if (dx >= 1 && dx <= n) {
                for (int z = 1; z <= n; z++) {
                    if (abs(z - j.se) > 1 && a[dx][z] < i) {
                        dp[i] = max(dp[i], dp[a[dx][z]] + 1);
                        if (i == 3 && dp[3] == 1) { // && a[dx][z] == 3) {
                            cout << j.fi << ' ' << j.se << endl;
                            cout << dx << ' ' << z << endl;
                            cout << endl;
                        }
                    } 
                }
            }

            dx = j.fi + 1;
            if (dx >= 1 && dx <= n) {
                for (int z = 1; z <= n; z++) {
                    if (abs(z - j.se) > 1 && a[dx][z] < i) {
                        dp[i] = max(dp[i], dp[a[dx][z]] + 1);
                    } 
                }
            }

                //  dy
            int dy = j.se - 1;
            if (dy >= 1 && dy <= n) {
                for (int z = 1; z <= n; z++) {
                    if (abs(z - j.fi) > 1 && a[z][dy] < i) {
                        dp[i] = max(dp[i], dp[a[z][dy]] + 1);
                    } 
                }
            }

            dy = j.se + 1;
            if (dy >= 1 && dy <= n) {
                for (int z = 1; z <= n; z++) {
                    if (abs(z - j.fi) > 1 && a[z][dy] < i) {
                        dp[i] = max(dp[i], dp[a[z][dy]] + 1);
                    } 
                }
            }
        }
    }


    cout << endl;
    int res = 0;
    for (auto i : d) {
        cout << i << ' ' << dp[i] << endl;
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}