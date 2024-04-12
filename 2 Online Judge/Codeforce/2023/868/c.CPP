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

ll cnt[10000003];
int a[1005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int>f;
    for (int i = 1; i <= n; i++) {
        int tmp = a[i];
        int x = sqrt(tmp);
        for (int j = 2; j <= x; j++) {
            if(tmp % j == 0) {
                if (cnt[j] == 0) f.pb(j);
                while (tmp % j == 0) {
                    cnt[j]++;
                    tmp /= j;
                }
            }
        }
        if (tmp > 1) {
            if (cnt[tmp] == 0) f.pb(tmp);       
            cnt[tmp]++;
        }
    }

    ll res = 0;
    ll z = 0;
    for (auto i : f) {
        res += cnt[i]/2;
        if (cnt[i] % 2 == 1) z++;
    }
    res += z/3;
    cout << res << endl;
    for (auto i : f) {
        cnt[i] = 0;
    }

    // cout << endl;
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