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
 
void solve() {

    long long a,b,c;
    cin >> a >> b >> c;
    long long x,y;
    int check = 0;
    long long a1,b1,c1;

    a1 = a, b1 = b, c1 = c;
    long long m;
    if (a != 0) {
        if ((2*b - c) % a == 0) {
            m = (2*b-c) / a;
            a1 = m*a;
            if (a1 > 0 && m > 0) check = 1;
        }
    }

    if (c != 0) {
        if ((2*b - a) % c == 0) {
            m = (2*b-a) / c;
            c1 = m*c;
            if (c1 > 0 && m > 0) check = 1;
        }
    }
    
    if (b != 0) {
        if ((a + c) % (2*b) == 0) {
            m = (a+c) / (2*b);
            b1 = m*b;
            if (b1 > 0 && m > 0) check = 1;
        }
    }
    
    if (check == 1) cout <<"yes" <<endl;
    else cout << "no" <<endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}