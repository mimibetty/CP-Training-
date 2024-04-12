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

int a[200005];
int b[200005];
int res[200005];
void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }
    if (a[1] != n) {
        cout << "NO" <<endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[n-i + 1];
        // cout << b[i] << ' ';
    }
    for (int i = 1; i <= n; i++) {
        int l = 0, r = n; 
        while (l < r) {
            int mid = (l + r)/2;
            if (b[mid] >= i) {
                r = mid;
            }
            else l = mid + 1;
            // cout << l << ' ' <<r <<endl;
        }
        res[i] = n - l + 1;
        // cout <<i << ' ' << n-l + 1 << endl;
        // cout << n-l+1 << ' ';
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        if (res[i] != a[i]) {
            ok = 0;
            break;
        }
    }

    if (ok) {
        cout << "YES" <<endl;
    }
    else cout << "NO" << endl;
    for (int i = 1; i <= n; i++) {
        // cout << res[i] << ' ';
        res[i] = 0;  
    } 
    // cout <<endl;
    // for (int i = 1; i <= n; i++) {
    //     cout <<res[i] << ' ';
    // }
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