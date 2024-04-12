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
    int n;
    cin >> n;
    vector<int>res;
    // res.pb(n);
    long long x = 1;
    while (x <= n) {
        x *= 2;
    }    
    if (x > n) x/=2;
    // cout << "Xxx" << x <<endl;
    long long hieu = n-x;
        vector<int> z;
    while (hieu > 0) {
        ll f  = 1;
        while (f < hieu) {
            f *= 2;
        }    
        if (f > hieu) f/=2;
        hieu -= f;
        z.pb(hieu);
    }
    reverse(All(z));
    
    ll tmp = n;
    for (auto i :z) {
        tmp -= i;
        res.pb(tmp);
    }

    while (x > 1) {
        res.pb(x);
        x /= 2;
    } 
    res.pb(1);
    cout << res.size() << endl;
    for (auto i : res) cout << i << ' ';
    EL;

    // cout << x << endl;
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