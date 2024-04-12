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
int cnt[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n ;i++) {
        cin >> a[i];
    }
    vector<ll>du;
    vector<ll>thieu;
    for (int i = 1; i < n ; i++) {
        ll x = a[i] - a[i-1];
        if (x >= 1 && x <= n) {
            cnt[x]++;
            if (cnt[x] > 1) {
                du.pb(x);
            }
        }
        else du.pb(x);
    }
    for (int i = 1;i <= n; i++) {
        if (cnt[i] == 0) {
            thieu.pb(i);
        }
    }
    // for (int i  =1; i < n;i++) {
    //     cout << a[i] - a[i-1] << ' ';
    // }
    // EL;
    // cout <<"Duu   "  <<  du.size() << endl;
    // for (auto i : du) cout << i << ' ';
    // EL;
    // cout <<"thiue  " <<   thieu.size() << endl;
    // for (auto i : thieu) cout << i << ' ';
    // EL;

    if(thieu.size() > 2) {
        cout << "NO" << endl;
    }
    else if (thieu.size() == 2) {
        if (du.size() == 1) {
            ll xx = du[0];
            ll aa = thieu[0] + thieu[1];
            if (xx == aa) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    else if (thieu.size()== 1) {
         cout << "YES" << endl;
    }


    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
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
    while (t--)   
    solve();
    
    return 0;
}