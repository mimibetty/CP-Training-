#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;

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
const double PI = acos(-1);
const int limx = 1e6;

int a[205][205];
int psngang[205][205];
int psdoc[205][205];
bool check(int i, int j, int k) {
    if ((psngang[i][j+k] - psngang[i][j-1]) != (k+1)) return 0;
    if ((psngang[i+k][j+k] - psngang[i+k][j-1]) != (k+1)) return 0;
    if ((psdoc[i+k][j] - psdoc[i-1][j]) != (k+1)) return 0;
    if ((psdoc[i+k][j+k] - psdoc[i-1][j+k]) != (k+1)) return 0;
    
    return 1;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psngang[i][j] = psngang[i][j-1] + a[i][j];
            psdoc[i][j] = psdoc[i-1][j] + a[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                if (i+k > n || j+k > m) break;
                if (check(i,j,k) == 1) res = max(res, (k+1)*(k+1));
                else break;
            }
        }
    } 
    cout << res;
    return 0;
}