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

int a[30005];
int c[5];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            c[a[i]%3]++;
        }

        // cout << c[0] << ' ' << c[1] << ' ' << c[2] <<endl ;
        ll res = 0;
        ll sum = c[0] + c[1] + c[2];
        sum/= 3;
        for (int i = 0; i < 3; i++) {
            while (c[i] > sum) {
                int vt = i+1;
                ll dis = 1;
                ll pass = 0;
                if (vt == 3) vt = 0;
                while(c[vt] >= sum) {
                    vt++;
                    dis++;  
                    if (vt == 3) vt = 0;

                } 

                int need = sum - c[vt];
                if (c[i] - need >= sum) {
                    pass = need;
                    c[i] -= need;
                    c[vt] += need;
                    res += (need*dis);
                }
                else {
                    pass = (c[i] - sum);
                    c[vt] += pass;
                    res += (dis*pass);
                    c[i] = sum;
                } 
                // cout << i << ' ' << vt << ' ' << pass <<endl;
                // cout << c[i] << ' ' << c[vt] << endl;
            }
        }

        cout << res << endl;

    }
    return 0;
}