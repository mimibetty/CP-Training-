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
#define whatIs(x) cerr << "Line " << _LINE_ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);

long double solve(int x1, int y1, int x2, int y2) {
    long double res = 0;
    long double a = abs(x1-x2);
    long double b = abs(y1-y2);
    a = 1.0000 * a * a;
    b = 1.0000 * b * b;
    res = 1.0000*(a + b);
    res = 1.0000*sqrt(res);

    return res;
}

int maxval[2005];
int minval[2005];

int main() {

    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int>a;
    set<int>s;

    for (int i = -1000; i <= 1000; i++) {
        maxval[i + 1000] = -1e9;
        minval[i + 1000] = 1e9;
    }

    for (int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        s.insert(x);
        maxval[x + 1000] = max(maxval[x + 1000], y);
        minval[x + 1000] = min(minval[x + 1000], y);
    }

    for (auto i : s) a.pb(i);

    // for (auto i : a) cout << i << endl;
    long double res = 0;
    precision(4);

    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            // cout << solve(a[i], maxval[a[i]], a[j], maxval[a[j]]) <<endl;
            // cout << solve(a[i], maxval[a[i]], a[j], minval[a[j]]) <<endl;
            // cout << solve(a[i], minval[a[i]], a[j], maxval[a[j]]) <<endl;
            // cout << solve(a[i], minval[a[i]], a[j], minval[a[j]]) <<endl;


            res = max(res, solve(a[i], maxval[a[i] + 1000], a[j], maxval[a[j] + 1000]));
            res = max(res, solve(a[i], maxval[a[i] + 1000], a[j], minval[a[j] + 1000]));
            res = max(res, solve(a[i], minval[a[i] + 1000], a[j], maxval[a[j] + 1000]));
            res = max(res, solve(a[i], minval[a[i] + 1000], a[j], minval[a[j] + 1000]));
        }
    }

    // cout << solve(2,-1,2,-2);
    cout << res << endl;
    return 0;
}