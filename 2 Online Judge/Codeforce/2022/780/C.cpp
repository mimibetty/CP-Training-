
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, S, r) for (int i = l; i < r; i++)
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

int dp[200005][5]; // xau dai nhat tai vi tri i,  0/1  0 la vi tri dau, 1 la sau
int last[200005][40];

void solve() {
	string s;
    cin >> s;
    int n = s.size();
	s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 25; j++) {
            last[i][j] = last[i-1][j];    
        }
        int ch = s[i] - 'a';

        last[i][ch] = i; 
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        int x = s[i] - 'a';

        if (last[i][x] > 0) {
            dp[i][1] = max(dp[i][1], dp[last[i][x]][0] + 2); 
        }

        res = max({dp[i][0], dp[i][1], res});
    }
    cout << max(0, res - n) <<endl;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 0;
    }
}   


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;

 	while(t--) {
 		solve();
 	}
    return 0;
}