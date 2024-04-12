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
 
long long dp[10005];

long long solve(string &s) {
    int n = s.size();
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    if (s[n - 2] == 'B') dp[1] = 1;
    else dp[1] = 2;
    for (int i = 2; i < n; i++) {
        if (s[n - i - 1] == 'B') dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int num = 6;
    map<char,long long>d;

    for (int bit = 0; bit < (1 << num); bit++) {
        string s;
        for (int i = 0; i < num; i++) {
            if (bit & (1 << i)) s += 'A';
            else s += 'B';
        }
        d[s] = solve(s);
        // cout << s << ' ' << solve(s) << endl;
    }

    for (auto i : d) cout << d.fi << ' ' << d.se <<endl;

    return 0;
}