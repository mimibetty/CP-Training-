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

bool dp[1000005];
int a[1005];
ll w,f;
ll s;
int n;

bool check(int m) {
    for (int i = 1; i <= s; i++) {
        if (dp[i]) {
            ll a1 = f*m;
            ll a2 = w*m;
            if (a1 >= i && a2 >= s - i) return 1;
            swap(a1,a2);
            if (a1 >= i && a2 >= s - i) return 1;
               
        }
    }
    return 0;
}
void solve() {
    cin >> w >> f;
    cin >> n;
    s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = s; i >= 0; i--) {
            if (dp[i] && i + a[j] <= s) dp[i+a[j]] |= dp[i];
        }
    }

    int l = 1, r = 1e6;
    while (l < r) {
        int m = (l + r)/2;
        if (check(m)) {
            r = m;
        }
        else l = m + 1;
        // cout << l << ' ' <<r << endl;
    }
    cout << l << endl;
    for (int i = 1; i <= s; i++) dp[i] = 0;
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
    solve();
    
    return 0;
}