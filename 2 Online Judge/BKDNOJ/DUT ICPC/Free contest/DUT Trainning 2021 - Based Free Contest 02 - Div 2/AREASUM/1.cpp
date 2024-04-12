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
const ll MOD = 1e9+7;
const double PI = acos(-1);
const int limx = 1e6;

ll a[100005], b[100005];
ll ps1[100005], ps2[100005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    
    for (int i = 1; i <= n; i++) {
        ps1[i] = ps1[i-1] + a[i];
        // cout <<ps1[i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= m; i++) {
        ps2[i] = ps2[i-1] + b[i];
    }
    ll sum1 = 0, sum2=0;

    for (int i = 1; i < n; i++) {
        sum1 += (ps1[n] - ps1[i] - (a[i]*(n-i)));
        // cout << i << ' ' << (ps1[n] - ps1[i] - (a[i]*(n-i))) << ' ' << sum1 <<  endl;
    }
    // cout << endl << sum1;

    for (int i = 1; i < m; i++) {
        sum2 += (ps2[m] - ps2[i] - (b[i]*(m-i)));
        // cout << i << ' ' << (ps1[n] - ps1[i] - (a[i]*(n-i))) << endl;
    }
    // cout << sum1 << ' ' << sum2 << endl;
    sum1%=MOD;
    sum2%=MOD;
    
    cout << (sum1 * sum2)%MOD ;
    return 0;
}