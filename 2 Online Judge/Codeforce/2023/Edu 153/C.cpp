/*
link submit: 
Note:

// gọi dp[i] = 0|1 là kết quả nếu đặt tại nó sẽ chiến thắng  
+ nếu đặt tại i và tồn tại j với aj < ai, j < i và dp[j] = 1 thì người thứ 2 sẽ 
cố tình đi đến j để chiến thắng => người 1 thua => dp[i] = 0;
 
+ với mọi j < i, aj >= ai , nếu đặt tại i thì người tiếp theo sẽ ko đi được 
=> người 1 thua  => dp[i] = 0;

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

int a[300005];
int dp[300005];
void solve1() {
    int n;
    cin >> n;


    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    // dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        bool ok = 1;
        for (int j = 1; j < i; j++) {
            // if(a[j] < a[i] && dp[j] == 1) {
            //     dp[i] = 0;
            // }
            if (a[j] < a[i]) {
                ok = 0;
            }
        }
        if (ok == 1) dp[i] = 0;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) s += dp[i];
    cout << s << endl;
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
    }
}


void solve2() {
    int n;
    cin >> n;


    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    // dp[1] = 0;
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        if (mn >= a[i]) dp[i] = 0;
        mn = min(a[i], mn);
    }
    int pre_min = 1e9;
    for (int i = 1; i <= n; i++) {
        if (pre_min < a[i]) dp[i] = 0;
        if (dp[i] == 1) {
            pre_min = min(pre_min, a[i]);
        }
    }
    int s = 0;
    for (int i = 1; i <= n; i++) s += dp[i];
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    // EL;
    cout << s << endl;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
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
    while (t--) {
        solve2();

    }
    
    return 0;
}