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
ll modd = 1000000007;
ll ps[200005];
ll s1[200005];
ll poww(int b) {
    if (b == 0) return 1;
    ll p = poww(b/2);
    if (b % 2 == 0) return p * p % modd;
    else return p * p % modd * 2 % modd;
}
void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    
    cin >> s;
    s = ' ' + s;
    ll p = 1;
    for (int i = 1; i <= n; i++) {
        p *= 2;
        if (p >= modd) {
            p -= modd;
        }
        ps[i] = ps[i-1];
        s1[i] += s1[i-1]; 
        if (s[i] == '1') {
            ps[i] += p;
            s1[i] ++;
        } 
    }
    set<ll>ss;
    for (int i = 1; i <= k; i++) {
        int l,r;
        cin >> l >> r;
        ll x = ps[l-1] + ps[n] - ps[r];
        if (x < 0) x += modd;
        if (x >= modd) x -= modd;

        int cnt = s1[r] - s1[l-1];
        ll tmp = 0;
        if (cnt > 0) {
            int rr = r;
            int ll = r - cnt + 1; 
            long long f1 = poww(ll);
            long long f2 = poww(rr-ll+1) - 1;
            if (f2 < 0) f2 += modd;
            if (f2 >= modd) f2 -= modd;

            tmp = f1 * f2 % modd;
        }
        ll temp = (x + tmp) % modd;
        ss.insert(temp);
        cout << l << ' ' << r << ' ' << temp << endl;
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
    
    return 0;
}
