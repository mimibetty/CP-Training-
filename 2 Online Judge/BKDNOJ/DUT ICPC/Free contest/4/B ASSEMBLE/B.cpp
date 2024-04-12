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


vector<pair<int,int>>a[1005];
int cnt = 0;
int n,x;

int solve(int mid) {
    int money = x;

    for (int i = 1; i <= cnt; i++) {
        int minval = 1e9;
        for (auto j : a[i]) {
            if (j.fi >= mid) minval = min(minval,j.se); 
        }
        money -= minval;
        if (money < 0) return 0;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    map<string,int>d;
 	cin >> n >> x;

 	for (int i = 1; i <= n; i++) {
 		string s1,s2;
 		cin >> s1 >> s2;
 		int quality,price;
 		cin >> price >> quality;
        if (d[s1] == 0){
            cnt++;
            d[s1] = cnt;
        }
        a[d[s1]].pb({quality,price});
 	}
    for (int i = 1; i <= cnt; i++) {
        sort( a[i].begin(), a[i].end());
    }

    // for (int i = 1; i <= cnt; i++) {
    //     for (auto j : a[i]) cout << j.fi << ' ' << j.se << endl;
    //         cout << endl;
    // }
    int lower = 0, upper = 1e9;
    int mid;
    while (lower < upper) {
        mid = (lower + upper)/2;
        if (solve(mid) == 1) lower = mid + 1;
        else upper = mid;
        // cout << mid <<' ' << solve(mid ) << endl;
    }
    if (solve(lower) == 0 && lower != 0) lower--;
    cout << lower;
    return 0;
}