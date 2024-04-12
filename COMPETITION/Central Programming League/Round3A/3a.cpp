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
int dp[1505][1505];
array<int, 3> b[2250005];

int main() {
     if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    int idx = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[++idx] = {a[i][j], i, j};
            dp[i][j] = -1e9;
        }
    }

    sort(b + 1, b + n * n + 1);

    dp[x][y] = 1;
    for (int t = 1; t <= n * n; t++) {
        // i - 1, i + 1, j - 1, j + 1
        // j - 2, j + 2, i - 2, i + 2
        auto [val, i, j] = b[t];

        if (i - 1 >= 1) {
            for (int v = 1; v <= j - 2; v++) {
                if (val > a[i - 1][v]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][v] + 1);
                }
            }

            for (int v = j + 2; v <= n; v++) {
                if (val > a[i - 1][v]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][v] + 1);
                }
            }
        }
        
        if (i + 1 <= n) {
            for (int v = 1; v <= j - 2; v++) {
                if (val > a[i + 1][v]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][v] + 1);
                }
            }

            for (int v = j + 2; v <= n; v++) {
                if (val > a[i + 1][v]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][v] + 1);
                }
            }
        }

        if (j - 1 >= 1) {
            for (int u = 1; u <= i - 2; u++) {
                if (val > a[u][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[u][j - 1] + 1);
                }
            }

            for (int u = i + 2; u <= n; u++) {
                if (val > a[u][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[u][j - 1] + 1);
                }
            }
        }

        if (j + 1 <= n) {
            for (int u = 1; u <= i - 2; u++) {
                if (val > a[u][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[u][j + 1] + 1);
                }
            }

            for (int u = i + 2; u <= n; u++) {
                if (val > a[u][j + 1]) {
                    dp[i][j] = max(dp[i][j], dp[u][j + 1] + 1);
                }
            }
        }

        // cout << dp[i][j] << endl;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << dp[i][j] << ' ';
            res = max(res, dp[i][j]);
        }
        // cout << endl;
    }
    cout << res;

    return 0;
}