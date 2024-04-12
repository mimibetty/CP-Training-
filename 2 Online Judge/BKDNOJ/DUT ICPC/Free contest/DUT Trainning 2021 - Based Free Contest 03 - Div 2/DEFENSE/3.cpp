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

bool check(ld xa,ld ya,ld vxa,ld vya,ld xb,ld yb,ld vxb,ld vyb) {
    if (xa != xb && ya != yb && vxa == vxb && vya == vyb) return 0;
    if (xa != xb && vxa == vxb) return 0;
    if (ya != yb && vya == vyb) return 0;
    return 1; 
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    ld xa,ya,vxa,vya;
    ld xb,yb,vxb,vyb;
    cin >> xa >> ya >> vxa >> vya;
    cin >> xb >> yb >> vxb >> vyb;
    if (abs((xb - xa)*(vya - vyb) - (yb - ya)*(vxa - vxb)) <= 1e-4) {
        precision(4);
        ld t1 = 1.0000 * (xb-xa)/(vxa - vxb);
        ld t2 = 1.0000 * (yb-ya)/(vya - vyb);
       
        bool done = 1;
        if (t1 < 0 || t2 < 0) done = 0;
        if (check( xa, ya, vxa, vya, xb, yb, vxb, vyb) == 0) done = 0;

        if (done == 0) cout << -1;
        else cout << vxa * t1 + xa << ' ' << vya * t1 + ya; 
    } 
    else cout << -1;
    return 0;
}