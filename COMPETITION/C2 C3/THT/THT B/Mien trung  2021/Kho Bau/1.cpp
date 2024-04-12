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

const int inf = 1e7;

int a[105];
int check[105][200005];
int d[105][200005]; // dp[vi tri][sum1 - sum2] = sum1  > ans = tong - 2sum1 if (s1 - s2 == 0)

int dp(int vt, int tong ) {
    if (check[vt][tong] == 1) return d[vt][tong];
    
    check[vt][tong] = 1;
    int res = -inf;

    // cout <<"VT  "<<  vt << ' ' << tong <<  endl;
    if (vt == 0) {
        if (tong == 100000) res = 0;
        else res = -inf;
    }
    else {
        res = max(res, dp(vt-1,tong));
        res = max(res, dp(vt-1,tong - a[vt]));
        res = max(res, dp(vt-1,tong + a[vt]) + a[vt]);
    }
    // cout <<"KQ  " << res << endl;
    d[vt][tong] = res;
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	while (cin >> n) {
        int sum = 0;
        int check12 = 0;

        for (int i = 1; i <= n; i++) {
 			cin >> a[i];
            sum += a[i];
 		     if (a[i] > 1e3) check12 = 1;
        }
            // cout << sum << endl;

        if (check12 == 1) { // sub 1,2
            bitset<25>bs,subbit;
            int res = sum;
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int bit = 0; bit < (1 << n); bit++) {
                for (int i = bit; i ; i = (i - 1) & bit) {
                    bs = bit;
                    subbit = i;

                    for (int i = 0; i < n; i++) {
                        if (bs[i] == 1) {
                            if (subbit[i] == 1) { // group 1
                                sum1 += a[i+1];
                            }
                            else { // group 2
                                sum2 += a[i+1];
                            }
                        }
                        else { // group 3 
                            sum3 += a[i+1];
                        }
                    }

                    if (sum1 == sum2) res = min(res, sum3);
                    
                }
            }
            cout << res <<endl;
        }
        else {
     		long long x = dp(n,1e5);
            // cout << x << endl;
            cout << sum - 2*x << endl;
            // cout <<  d[n][100000] << endl;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= 2e5; j++) check[i][j] = 0;
            }
        }
 	}

    return 0;
}