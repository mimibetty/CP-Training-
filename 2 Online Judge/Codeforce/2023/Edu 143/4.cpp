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

ll a[300005];
ll f[300005];
ll p[300005];
ll modd = 998244353;

ll pw(ll a, ll b) {
    if (b == 0) return 1;
    ll q = pw(a,b/2);
    if (b % 2 == 0) {
        return q * q % modd;
    }
    else return q * q % modd * a % modd;
} 

bool check(ll a, ll b, ll c) {
    vector<int>f;
    f.pb(a);
    f.pb(b);
    f.pb(c);
    sort(All(f));
    if(f[0] == f[1] || f[1] == f[2]) {
        return f[0] == f[1];
    }
    else return 0;
}

ll combi(ll a, ll b) {
    return f[b] * p[a] % modd * p[b-a] % modd;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i-1] * i % modd;
    } 
    
    p[0] = p[1] = 1;
    p[n] = pw(f[n],modd - 2);

    for (int i = n-1; i >= 2; i--) {
        p[i] = p[i+1] * (i+1) % modd;
    }




    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt0 = 0, cnt2 = 0, cnt1 = 0;
    ll res = combi(n/6,n/3);

    for (int i = 3; i <= n; i+=3) {
        if (a[i] == a[i-1] && a[i-1] == a[i-2]) {
            cnt2++;
        }
        else if (check(a[i-1], a[i], a[i-2])) {
            cnt1++;
        }
        else {
            cnt0++;
        }
    }
    // cout << cnt2 << ' ' << cnt1 << ' ' << cnt0 << endl;
    
    for (int i = 1; i <= cnt2; i++) {
        res = res * 3 % modd;
    }
    // cout << res << endl;
    for (int i = 1; i <= cnt1; i++) {
        res = res * 2 % modd;
    }
    
    cout << res << endl;
    return 0;
}