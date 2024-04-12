#include<bits/stdc++.h>
using namespace std;

const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;


#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

long long dp[5005][5005];
long long ps[5005];
long long a[5005];
long long predp[5005][5005];

/*// dp[n][k] tổng lớn nhất tại vị trí n chia ra k dãy liên tiếp
    tại vt n ko chọn dp[i][k] = max(dp[i][k], dp[i-1],[k])
    chọn > for (j = 0 > i) dp[i][k] = max (dp[i][k] , dp[j][k-1] + s[i] -  s[j])
    s[i] - s[j] = tổng trong khoảng j+1 > i, sử dụng prefix sum
*/
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,num;
    cin >> n >> num;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = a[i] + ps[i-1];
    }
    
    // for (int i = 1; i <= n; i++) {
    //     for (int k = 1; k <= num; k++) {
            
    //         dp[i][k] = max(dp[i][k], dp[i-1][k]); // ko chon
    //         for (int j = 0; j < i; j++) {
    //             dp[i][k] = max(dp[i][k], dp[j][k-1]  - ps[j] + ps[i]); // chọn tập k gồm j+1 > i
    //         }
    //     }
    // }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= num; j++) {
            dp[i][j] = -oo;
            predp[i][j] = -oo;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= num; k++) {
            
            dp[i][k] = max(dp[i][k], dp[i-1][k]); // ko chon
            dp[i][k] = max(dp[i][k], predp[i-1][k-1] + ps[i]); // chọn tập k gồm j+1 > i
            

            predp[i][k-1] = max(predp[i-1][k-1], dp[i][k-1] - ps[i]);
            
            //predp i,k = max dp 0k, dp1k .... dp i-1 k 
        }
    }
    cout << dp[n][num];
    return 0;
}