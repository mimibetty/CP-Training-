S#include<bits/stdc++.h>
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

int dem[10000]
int a[45];
int d[1000006];
bool d2[1000006];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    int x = 1e9;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++) {
            cin >> a[i];
            x = min(x,a[i]);
        }
        bool done = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] != a[i+1]) {
                done = 1;
                break;
            }
        }
        if (done== 0) {
            cout << -1 << endl;
            continue;
        }

        // cout << x << endl;
        bool check = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 1e6; j++) {
                if (i == 1) d[j] = (a[i] % j + j) % j;
                else {
                    if (d[j] != ((a[i] % j + j) % j)) d[j] = 0;
                }
                // if (j == 2) cout << i << ' ' << (a[i] % j + j) % j << endl; 
            }
        }
        for (int i = 1e6; i >= 1; i--) {
            if (d[i] != 0) {
                cout << i << endl;
                break;  
            }
            if (i == 1) cout << 1 << endl; 
        } 
        for (int i = 1; i <= 1e6; i++) d[i] = 0;

    }
    // cout << __gcd(4,2);
    return 0;
}