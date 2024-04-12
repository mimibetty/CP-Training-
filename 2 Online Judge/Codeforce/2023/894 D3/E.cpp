/*
link submit: 
Note: quy về tìm 1 tập hợp sao cho x1 + x2 + ... + x_z - (vt[x[z]])*d max, với z  <= m 
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;
 
typedef tree<pair<long long, long long>,null_type,less<pair<long long, long long>>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;
 
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

ll a[200005];
// long long dp[20005][300];
void solve() {
    int m;
    ll n,d;
    cin >> n >> m >> d;
    vector<vector<long long>>dp;
    dp.resize(n+1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(m + 1);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++ ) {
        for (int k = 0; k <= m; k++) {
                dp[i][k] = -1e18;
        }  
    }
    dp[0][0] = 0;


    ll res = 0;
    for (int i = 1; i <= n; i++ ) {
        for (int j = 0; j < i; j++) {
            for (int k = 1; k <= min(m,i); k++) {
                dp[i][k] = max(dp[i][k], dp[j][k-1] + a[i] - (i-j) * d);
                dp[i][k] = dp[j][k-1] + a[i] - i*d  + j*d;
                res = max(res, dp[i][k]);
                // cout << i << ' ' << j << ' ' << k << "    " << dp[i][k]<<"     "
                // << dp[j][k-1] << ' ' << a[i] - (i-j) * d << endl;
            }
        }  
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) dp[i][j] = 0;
    }
    cout <<res << endl;
}

void solve2() {
    int m;
    ll n,d;
    cin >> n >> m >> d;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    ll sum = 0;
    multiset<int>s;
    
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            if (s.size() < m) {
                sum += a[i];
                s.insert(a[i]);
                res = max(res, sum - i*d);
            }
            else {
                auto firstElement = s.begin();
                if (a[i] >  *firstElement) {
                    sum = sum - *firstElement + a[i];
                    res = max(res, sum - i*d);
                    s.erase(firstElement);
                    s.insert(a[i]);
                }  
            }
        }
    }
    cout <<res <<endl;
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
    while (t--)
    solve2();
    return 0;
}