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
    // vector <ll>ar1,ar2;
    ll sum1 = 0,sum2 = 0;
    for (int i = 1 ; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            sum1 += (abs(a[i] - a[j]));
        }
    }
    for (int i = 1 ; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
            sum2 += (abs(b[i] - b[j]));
        }
    }
    
    cout << (sum1%MOD * sum2%MOD) %MOD;
    return 0;
}