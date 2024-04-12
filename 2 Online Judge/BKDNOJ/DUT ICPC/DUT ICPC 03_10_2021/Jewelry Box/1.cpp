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
        lld res1 = 0, res2 = 0;
        int x,y;
        cin >> x >> y;
        lld h1 = 0, h2 = 0;

        lld b= -4*(x+y);
        lld a = 12;
        lld c = x*y;
        lld delta = b*b - 4*a*c;
        h1 = abs(-b + sqrt(delta))/(2*a);
        h2 = abs(-b - sqrt(delta))/(2*a);
        // -b+candelta / 2a

        res1 = (x-(2*h1)) * (y - (2*h1)) *h1;
        res2 = (x-(2*h2)) * (y - (2*h2)) *h2;
        precision(12);
        cout << max(res1,res2) << endl;
    }

    return 0;
}