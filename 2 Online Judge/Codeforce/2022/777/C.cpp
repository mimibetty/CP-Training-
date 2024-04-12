#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
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
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);

int a[105][105];
int b[105][105];
int n,m;

bool check(int x, int y ) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    return 0;
}

void solve() {
    cin >> n >> m;
    vector<pair<int,int>>res;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) a[i][j] = s[j-1] - '0'; 
    }
    
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == 0) { 
                if (check(i+1, j) == 1) {
                    if (b[i+1][j] == 0 && a[i+1][j] == 1) {
                        b[i+1][j] = 1;
                        res.pb({i,j});
                        res.pb({i+1,j});
                    }                    
                }

                if (check(i, j+1) == 1) {
                    if (b[i][j+1] == 0 && a[i][j+1] == 1) {
                        b[i][j+1] = 1;
                        res.pb({i,j});
                        res.pb({i,j+1});
                    }                    
                }

               

                if (check(i, j+1) == 1) {
                    if (b[i][j+1] == 0 && a[i][j+1] == 1) {
                        b[i][j+1] = 1;
                        res.pb({i,j});
                        res.pb({i,j+1});
                    }                    
                }

            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j];
            if (a[i][j] != b[i][j]) {
                // cout << -1 << endl;
                // return;
            }
        }
        cout << endl;
    }

    // cout << res.size()/2;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].fi << ' ' << res[i].se << ' ';
        if (i % 2 == 1) cout << endl;
    }
    res.clear();
    return ;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while(t--) {
 		solve();
 	}

    return 0;
}