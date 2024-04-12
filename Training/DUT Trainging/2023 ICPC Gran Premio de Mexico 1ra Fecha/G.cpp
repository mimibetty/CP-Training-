/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
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
// giả thiết 1, dp[i][n] >= tổng các dp[i-1][j] thì i là kq?
ll dp[1005][1005]; // số cách chọn để tại lần bốc i, tổng số quả bóng là j
void solve() {
    int n;
    cin >> n;
    // cout << n << endl;
    if (n == 1) {
        cout << "Jane" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = -1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            for (int k = 1; k <= i; k++) {
                if (j - k >= 0) {
                    if (dp[i-1][j-k] == 0) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
        EL;
    }

    cout <<n << ' ' << dp[1][n] << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();
    
    return 0;
}