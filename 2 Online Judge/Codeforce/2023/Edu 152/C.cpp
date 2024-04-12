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
ll modd = 1000000009;
ll modd2 = 1000000007;

ll ps[200005];
ll ps2[200005];
ll s1[200005];
ll poww(long long a, long long b, long long modd) {
    if (b == 0) return 1%modd;
    ll p = poww(a,b/2,modd);
    if (b % 2 == 0) return p * p % modd;
    else return p * p % modd * a % modd;
}

void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    
    cin >> s;
    s = ' ' + s;
    ll p = 1;
    ll p2 = 2;
    for (int i = 1; i <= n; i++) {
        p *= 2;
        p2 *= 7;
        if (p >= modd) {
            p %= modd;
        }
        
        if (p2 >= modd2) {
            p2 %= modd2;
        }
        ps[i] = ps[i-1];
        s1[i] += s1[i-1]; 
        ps2[i] = ps2[i-1];
        
        if (s[i] == '1') {
            ps[i] += p;
            s1[i] ++;
            ps2[i] += p2;
        } 
    }
    set<ll>ss;
    for (int i = 1; i <= k; i++) {
        int l,r;
        cin >> l >> r;
        ll x = ps[l-1] + ps[n] - ps[r];
        x %= modd;
        if (x < 0) x += modd;

        ll x2 = ps2[l-1] + ps2[n] - ps2[r];
        x2 %= modd2;
        if (x2 < 0) x2 += modd2;

        int cnt = s1[r] - s1[l-1];
        
        ll tmp = 0;
        ll tmp2 = 0;
        if (cnt > 0) {
            int r1 = r;
            int l1 = r - cnt + 1; 
            long long f1l = poww(2,l1,modd);
            long long f1r = poww(2,r1-l1+1,modd) - 1;
            f1r %= modd;
            if (f1r < 0) f1r += modd;
            tmp = f1l * f1r % modd;

            long long f2l = poww(2,l1,modd);
            long long f2r = poww(2,r1-l1+1,modd) - 1;
            f2r %= modd2;
            if (f2r < 0) f2r += modd2;
            tmp2 = f2l * f2r % modd;
        }
        ll temp = (x + tmp) % modd;
        ll temp2 = (x2 + tmp2) % modd2;


        ss.insert({temp,tmp2});
        cout << l << ' ' << r << ' ' << tmp << ' ' << tmp2 << endl;
    }
    cout << ss.size();
    // for (auto i : ss) cout << i << ' ';
    EL;
    for (int i = 1; i <= n; i++) {
        ps[i] = s1[i] = 0;
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
    X*n + 
    return 0;
}