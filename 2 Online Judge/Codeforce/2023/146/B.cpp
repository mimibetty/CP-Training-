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
    ll a,b;
    cin >> a >> b;
    vector<int>f;

    

    ll res = 1e9;
    ll x = min(max(a,b), 1ll*100000);
    for (ll i = 1; i <= x; i++) {
        ll tmp = i - 1;
        tmp += (a/i);
        tmp += (b/i);
        if (a % i != 0) tmp++;

        if (b % i != 0) tmp++; 
        // cout << i << ' ' << tmp <<endl;
        res = min(res, tmp);
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
    while (t--) solve();
    return 0;
}