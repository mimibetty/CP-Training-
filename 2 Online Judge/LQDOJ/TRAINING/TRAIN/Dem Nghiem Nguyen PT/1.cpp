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


int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll res = 0;

        if (c == 0) {
            cout << "oo";
            cout << endl;
        }
        else if (c % 2 == 0) {
            if (a == 0) {
                if (b == 1 || b == -1) cout << "oo";
                else cout << 0;
            }
            else {
                if ((1-b)%a == 0) res++;
                if ((-1-b)%a == 0) res++;
                cout << res;
            }
            cout << endl;
        }
        else {
            if (a == 0) {
                if (b == 1) cout << "oo";
                else cout << 0;
            }
            else {
                if ((1-b)%a == 0) res++;
                cout << res;
            }
            cout << endl;
        }
    }   
    return 0;
}