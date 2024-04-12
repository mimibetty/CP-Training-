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

int dp[11][11]; 
// tại vị trí i, điền vào số j thì vị trí trong j trong s là bao nhiêu
// nếu tại 1 vị trí nào đó không tìm được thì in ra yes
int binary_search(const vector<int>& a, int x) {
    int left = 0;
    int right = a.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            result = a[mid];
            right = mid - 1;
        }
    }

    return result;
}


void solve() {
    string s;
    int n;
    string l,r;
    cin >> s;
    cin >> n >> l >> r;
    vector<int>vt[10];
    for (int i = 0; i < s.size(); i++) {
        int x = (s[i] - '0');
        vt[x].pb(i);
    }
   
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = -1;
        }
    }
    // for (auto i : vt[0]) cout << i << ' ';
    //     cout << endl;
    // cout << binary_search(vt[0],-1) << endl;
    for (int j = int(l[0] - '0'); j <= int(r[0] - '0'); j++) {
        dp[0][j] = binary_search(vt[j],-1);   
    }
    bool ok = 1;
    for (int i = 1; i < n; i++) {
        for (int j = int(l[i] - '0'); j <= int(r[i] - '0'); j++) {
            for (int k = int(l[i-1] - '0'); k <= int(r[i-1] - '0'); k++) {
                if (dp[i-1][k] != -1) {
                    if (dp[i][j] == -1) dp[i][j] = binary_search(vt[j], dp[i-1][k]);
                    else {
                        dp[i][j] = max(dp[i][j], binary_search(vt[j], dp[i-1][k]));
                    }                                       
                }
            }
            if (dp[i][j] == -1) {
                ok = 0;
                break;
            }
        }
    }
    if (ok == 0) {
        cout << "YES" << endl;
        return;
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = int(l[i] - '0'); j <= int(r[i] - '0'); j++) {
    //         if (dp[i][j] != -1) cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    //     }
    // }
    cout << "NO" << endl;
    // dp[i][j][k]  vị trí i, điền thằng j và vị trí i-1 điền thằng k thì thằng k
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
        solve();
    }
    return 0;
}