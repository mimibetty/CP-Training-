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

ll a[100005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,t;
    cin >> n >> t;

    while (t--) {
        int r, p;
        cin >> r >> p;

        if (p == 1) {

        }
        else {
            ll sum = 0;
            ll tb = 0;
            for (int i = 1; i <= r; i++) {
                sum += a[i];
            }
            tb = sum/r;
            ll x = 
        }
        // ll minval = 1e9;

        // while (p--) {
        //     int vt = 0;
        //     minval = 1e9;

        //     for (int i = r; i >= 1; i--) {
        //         minval = min(minval,a[i]);
        //         if (a[i] == min(minval,a[i])) {
        //             vt = i;
        //         }
        //     }
        //     a[vt]++;
            
        }

        // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        //     cout << endl;
    }


    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}