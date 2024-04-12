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

int dp[11]; 
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
   
    bool ok = 1;
    int last = -1;
    for (int i = 0; i < n; i++) {
        int maxx = -1;
        for (int j = int(l[i] - '0'); j <= int(r[i] - '0'); j++) {
            int result = -1;
            for (int k = last + 1; k < s.size(); k++) {
                if ((s[k] - '0') == j) {
                    result = k;
                    break;  
                } 
            }
            if (result == -1) {
                ok = 0;
                break;
            }
            maxx = max(maxx, result);
        }
        if (maxx == -1) {
            ok = 0;
            break;
        }
        last = maxx;
    }
    if (ok == 0) {
        cout << "YES" << endl;
        return;
    }
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