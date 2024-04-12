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

void solve() {
    int n,k,x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES" << endl << n << endl;
        for (int i = 1; i <= n; i++) cout << 1 << ' ';
            cout << endl;
        return;
    }
    for (int i = 1; i <= k; i++) {
        if (i == x) continue;
        if (n % i == x) continue;
        int x = n/i;
        int res = 0;
        res += n/i;
        if (n % i != 0) {
            res++;
            // cout << n% i << " ";  
        } 
        cout <<"YES" << endl;
        cout << res << endl;
        if (n % i != 0) {
            cout << n% i << " ";  
        } 
        for (int j = 1; j <= n/i; j++) {
            cout << i << " ";
        } 
        cout << endl;
        return;
    }
    cout << "NO" << endl;
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