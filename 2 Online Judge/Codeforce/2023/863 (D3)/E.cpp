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

ll mu[17];
map<ll,ll>d;
ll tinh(ll r) {
    if (r >= 4 && r < 10) {
        // cout << r << ' ' << 1 <<endl;
        return 1;  
    } 
    if (r < 4) {
        // cout << r << ' ' << 0 << endl;
        return 0;  
    } 
    if (d[r] != 0) return d[r];
    string s = to_string(r);
    int sizz = s.size();

    ll cs1 = s[0] - 48;
    ll res = 0;
    ll x = 0;
    ll y = 0, z = 0;
    if (cs1 > 4) x = mu[sizz - 1]; 
    else if (cs1 == 4) {
        x = r + 1 - cs1*mu[sizz-1]; 
    }
    if (cs1 != 4) y = tinh(r - cs1*mu[sizz-1]);
  
    if (cs1 <= 4) z = tinh(mu[sizz - 1] - 1) * cs1;
    else {
        z = tinh(mu[sizz - 1] - 1) * (cs1 - 1);
    }
    // ff += (x + y + z);
    res += (x + y + z);
    // cout << r << ' ' << x << ' ' << y << ' ' << z << " " << res <<endl;
    return d[r] = res;
}
int brute(int n) {
    int cnt = n;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        bool ok = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '4') {
                ok = 1;
                break;
            }
        }
        cnt -= ok;
        // if (ok == 1) {
        //     cout << i << endl;
        // }
    }
    return cnt;
}
void solve() {
    ll n;
    cin >> n;
    ll l = 1, r = 1e17;
    ll mid;
    while (l < r) {
        mid = (l + r) /2;
        if (mid - tinh(mid) >= n) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    mu[0] = 1;
    for (int i = 1; i <= 16; i++) {
        mu[i] = mu[i-1] * 10;
        // cout << i << ' ' << mu[i] << endl;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}