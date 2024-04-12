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
 
ll a[105][5]; // 1 la kg  , 2 la tien
ll d[105][50005];
bool check[105][50005];
ll dp(ll vt, ll val) {

    if (check[vt][val] == 1) return d[vt][val];
    if (vt == 0) {
        if (val <= 0) return 0;
        return 1e18;   
    }
    if (val <= 0) return 0; 

    for (int i = 0; i <= ((val/a[vt][1]) + 1); i++) {
        if (val - (i*a[vt][1]) <= 0) {
            return d[vt][val] + (a[vt][2]*i);
            break;
        }
        d[vt][val] = min(dp(vt-1,val - (i*a[vt][1]) + (i*a[vt][2])), d[vt][val]);
        check[vt][val] = 1;
    }
    // cout << vt <<' ' << val << ' ' << dp(vt,val) << endl;
    return d[vt][val];
   
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    int n, x;
    cin >> n >> x;
    
    for (int i = 1; i <= n; i++) cin >>a[i][1] >> a[i][2];
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= x; j++) cout << i << ' ' << j << ' '<< dp(i,j) << endl;
    // }

    cout << dp(n, x);
    return 0;
}