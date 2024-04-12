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

long long a[200005];
long long n,k;
long long sol(long long mid ) {
    ll res = 0;
    for (int i =1 ; i <= n; i++)  {
        res += max(1ll*0, mid - a[i]);
    }
    return res;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long l = 0, r = 1e9;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (sol(mid) > k) {
            r = mid-1;
        }
        else l = mid ;
        // cout << l << ' ' << r << endl;
    }
    while(sol(l+1) <= k) l++;
    // cout << sol(l) << ' '<<sol(l+1) << ' ';
    cout << l << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}