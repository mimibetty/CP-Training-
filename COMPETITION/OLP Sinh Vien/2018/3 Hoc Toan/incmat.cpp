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

vector<vector<long long>>a;
vector<vector<long long>>f;
vector<vector<long long>>b;

// ll a[100][100],f[100][100];

// update bảng (x1, y1) -> (x2, y2)
void update(int x1, int y1, int x2, int y2, int p) {
    b[x1][y1] += p;
    b[x1][y2 + 1] -= p;
    b[x2 + 1][y1] -= p;
    b[x2 + 1][y2 + 1] += p;
    return;
}
 
// calc (1, 1) -> (x, y) and after update
// f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
 
// calc (x1, y1) -> (x2, y2)
long long calc(int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
}
 
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int m, n;
    cin >> n >> m;

    a.resize(n+5);
    f.resize(n+5);
    b.resize(n+5);
    
    for (int i = 0; i <= n + 2; i++) {
    	a[i].resize(m+5);
    	f[i].resize(m+5);
        b[i].resize(m+5);	
    } 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }

    int q;
    cin >> q;
    // cout << q << endl;
    for (int z = 1; z <= q; z++) {
        ll x1, y1, x2, y2, d;
        cin >> x1 >> y1 >> x2 >> y2 >> d; 
        update(x1,y1,x2,y2,d);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = calc(i,j,i,j);
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
   return 0;
}