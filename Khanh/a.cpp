/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()

#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

const long long MOD = (1e9 + 7);
long long dp[100002],dp2[100005];
void solve() {
    int n;
    cin >> n;


    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;      
        }

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            // for (int x = i - k; x >= 1; x--) {
            //     dp[i] += dp[x];
            //     dp[i] %= MOD;
            // }
            if (i > k) {
                dp[i] += dp2[i-k];
            } 

            
            sum += dp[i];
            sum %= MOD;
        }
        cout << sum << endl;
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}

dp(vt + 1)  = dp(vt)

dp[n][k]
dp[1][x]
 ++++++
dp[2][x]
dp[3] = dp[2]
dp[n][k]????

dp[2][k]

dp[1][k]
dp[2][k]

dp[1] = dp[2]
dp[2] = dp[3]
dp[3][k]

2 
1,2
dp[3] = dp[2]
dp[4] = dp[3]
dp[5]

int f[1000]
tính fn = fn-1 + fn-2 
f1000 ???? ||| f1,f2,f3,f4
f1 = 1, f2 = 2, fi = ?

for (int i = 3; i <= n; i++) 
    fnext = f1 + f2 
    f1 = f2 
    f2 = fnext 

      f1 f2 
      1   2
      2   3
      3   4
      n-1 n 
tốn 3 phần tử bộ nhớ
n phần tửt
fi se là số fibo thứ n 

 dp(vt,k) = max dp(vt-1, val - h[vt]) + s[vt ]
                     dp(vt - 1, val)
                     dp[vt]  dpold = vt - 1
dp[5]  = dp[4]
dp[5] => old 
dp[6] = dpold 
dp[k]  = dpold[k]
dpold = dp
    dp[0] = 0;
    for (int i = 1; i <= x; i++) dp[i] = -1e9;
 
    dpOld[0] = 0;
    for (int i = 1; i <= x; i++) dpOld[i] = -1e9;
 
    for (int vt = 1; vt <= n; vt++) {
        for (int val = 0; val <= x; val++) {
            dp[val] = -1e9;
            if (val - h[vt] >= 0) {
                dp[val] = max(dp[val], dpOld[val - h[vt]] + s[vt]);  
                //cout << dp[val];
            } 
            dp[val] = max(dp[val], dpOld[val]);
 
             //cout << ' ' <<dp[val] << endl;
        }
 dp[i][j] = dp[i-1][x]
 thay vì tốn mảng dp[n][k]
thì mình có thể tối ưu lại thành dp[k] bằng việc sử dụng thêm 1 mảng dp2[k]
        for (int val = 0; val <= x; val++) {
           dpOld[val] = dp[val];
        }
    }
    
    for (int val = 0; val <= x; val++) {
        res = max(res, dp[val]);
    }
