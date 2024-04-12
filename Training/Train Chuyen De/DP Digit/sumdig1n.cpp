/*
link submit: https://lqdoj.edu.vn/problem/sumdig1n
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

vector<int>cs;
ll a,b;
ll d[18][180][2];

ll dp(int vt, int sum, bool exceed) {
    if (vt == cs.size()) {
        return sum;
    } 

    if (d[vt][sum][exceed] != -1) {
        return d[vt][sum][exceed];
    }

    int lim = 9;
    if (exceed == 0) {  // = 1  => cs[vt] optinal
        lim = cs[vt];
    }
    ll ans = 0;
    for (int digit = 0; digit <= lim; digit++) {
        bool NewExceed = exceed;
        if (digit < lim) {
            NewExceed = 1;
        }
        ans += dp(vt + 1, sum + digit, NewExceed);
    }

    return d[vt][sum][exceed] = ans;
}
ll sol(ll x) {
    cs.clear();
    ll tmp = x;
    while (tmp) {
        cs.pb(tmp%10);
        tmp /= 10;
    }
    reverse(All(cs));
    memset(d,-1,sizeof(d));

    ll res = dp(0,0,0);
    return res;
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
    cout << sol(t);
    return 0;
}