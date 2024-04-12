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

int a[100005];
int test(int l, int r) {
    int x = a[r];
    for (int i = l; i < r; i++) {
        x ^= a[i];
    }
    return x;
} 
int cnt[260];
int ps[100005];
void solve() {
    int n;
    cin >> n;
    bitset<5>bs;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ps[1] = a[1];
    for (int i = 2; i <= n; i++) {
        ps[i] = (ps[i-1]^a[i]);
    }
    cnt[0]++;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 256; j++) {
            if (cnt[j]) {
                // cout << i << ' ' << j << ' ' << res << ' ' << (ps[i] ^ j) << endl;
                res = max(res, (ps[i] ^ j));
            }
        }
        cnt[ps[i]]++;
    }
    // EL;
    // pii vt = {1,1};
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j<= n; j++) {
    //         if (test(vt.fi, vt.se) < test(i,j)) {
    //             vt = {i,j};
    //         }
    //     }
    // }
    // cout << test(vt.fi, vt.se) << ' ' << vt.fi << ' ' << vt.se << endl;
    cout <<res << endl;
    for (int i = 0; i <= 256; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) ps[i] = 0;

}
minn = 1e9;
for (int i = 1; i <= n; i++) {
    ps[r] = ps[i];
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