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

ll a[200005];

void solve() {
    int n;
    cin >> n;
    set<ll>s;
    unordered_map<ll,ll>cnt;
    ll maxval = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
        maxval = max(maxval,a[i]);
    }
    ll res = 0;
        
    for (auto i : s) {
        if(cnt[i] >= 3) {
            res += cnt[i]*(cnt[i]-1)*(cnt[i]-2);
        }
    }
    // cout << res <<endl;
    ll sqr = sqrt(maxval);
    
    for (int i = 2; i <= 5; i++) {
        for (auto j : cnt) {
            ll q = j.fi;
            ll tmp1 = q;
            ll tmp2 = q*i;
            ll tmp3 = q*i*i;
            // // cout << 100;
            if (cnt[tmp1] * cnt[tmp2]*cnt[tmp3]) {
                cout << i << ' ' << q <<endl; 
                cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << " " << cnt[tmp1] << ' ' <<cnt[tmp2] << ' ' << cnt[tmp3] << endl;
            }
            // // if (tmp3 > maxval) break;
            // res += cnt[tmp1] * cnt[tmp2]*cnt[tmp3];
        }
        cout << endl;
    }
    cout <<res;
    cout << endl;
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