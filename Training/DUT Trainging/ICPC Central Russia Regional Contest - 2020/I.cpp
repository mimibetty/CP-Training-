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

    // x^2 > n (n + 1) 
    // n*(n+q) = x*x
    // n*n + n*q = x^2
    // nq = x^2 - n^2 
    // q = x^2/n - n   
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<int>div;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n% i == 0) {
            div.pb(i);
            div.pb(n/i);
        }
    }
    ll res = 1e18;
    for (auto i : div) {
        ll x = n + i;
        if ((x*x - n*n)% n == 0) {
            // cout << x << ' ' << i << endl;;
            res = min(res, 1ll*(x*x - n*n)/n);
        }
    }
    cout <<res <<endl;
    return 0;
}
