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

pair<ld,ld>a[100005];
ld f[100005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+1+n);
    ld res = 1e9;
    do {
        // for (int i = 1; i <= )
        ld x = 0; 

        for (int  i = 1; i <= n; i++) {
            f[i] = a[i].fi + f[i-1];
            x = (1.0000*f[i]*a[i].se) + x;
            // cout << a[i].fi << ' ' << f[i] << ' ' << x << endl;
        }
        // cout << x << endl;
        precision(4);
        res = min(res,x);
        // cout << endl;

    } while(next_permutation(a + 1, a + 1 + n) );
  
    cout << res << endl;
    return 0;
}