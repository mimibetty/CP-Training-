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

ll x[200005];
void solve() {
    int n;
    cin >> n;
    vector<ll>a;
    vector<ll>b;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        // cout << x[i] << endl;
        if (x[i] >= 0) a.pb(x[i]);
        else b.pb(x[i]);
    }
    ll res = x[1]*x[2];
    if (a.size() > 0)    sort(All(a));
    if (b.size() > 0)    sort(All(b));
    

    if (a.size() >= 2) {
        // cout <<"11" << endl;
        res = max(res, a[a.size()-1]*a[a.size()-2]);
    }

        // cout <<"22" << endl;
    if (b.size() >= 2) {
        res = max(res, b[0]*b[1]);
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
    while (t--) {
        solve();
    }
    return 0;
}