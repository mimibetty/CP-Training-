#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
 
 
 
ll a[100005], b[100005],c[100005];
ll cost[10], val[10];
long long dp[1000005];
 
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
 
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,B;
    cin >> B >> n;
    for (int i = 1; i <= B; i++) {
        cin >> val[i] >> cost[i];
    }
 
    long double sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        long double p = a[i] + b[i] + c[i];
        p /= 2;
        long double s = 1.00* sqrt(1.00 * p*(p-a[i])*(p-b[i])*(p-c[i]) );
        sum += s;
    }
 
    sum /= 30;
    // sum = ceil(sum);
    long long zz = ceil(sum);
    // cout << sum <<endl;
    for (int i = 1; i <= 1000000; i++) dp[i] = 99999999;
 
    for (int i = 1; i <= 1000000; i++) {
        // dp[i] = dp[i-1];
        for (int j = 1; j <= B; j++) {
            if (i - val[j] >= 0) {
                dp[i] = min(dp[i], dp[i - val[j]] + cost[j]);
            }
        }
    }
    // long long num = 1ll*sum;
    long long res = 9999999999999;
 
    // for (ll i = 0; i <= 100000; i++) {
    //     if (i > sum) break; 
    //     for (ll j = 1; j <= B; j++) {
    //         long long sl = sum - i;
    //         sum /= val[i];
          
    //     }
    // }
 
    for (long long i = 0; i <= 1000000; i++) {
        for (int j = 1; j <= B; j++) {
            long long d = zz - i;
            if (d < 0) break;;
 
            d /= val[j];
 
            long long xx = i + val[j] * d;
            if (xx == zz) {
                res = min(res, dp[i] + d*cost[j]);
            }
        }
    }
    cout << res << endl;
    return 0; 
}