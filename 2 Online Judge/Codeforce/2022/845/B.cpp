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

// int a[1000];
void solve() {
    ll n;
    cin >> n;
    ll modd = 1e9+7;
    ll res = 0;
    
    ll x = 0;
    for (int i = 1; i <= n; i++) {
        res += x;
        x += 2;
    }
    for (int i = 1; i <= n; i++) {
        res = res * i % modd;
    }
    cout << res << endl;
    // for (int i = 1; i <= n; i++) a[i] = i;
    
    // do {
    //     int x = n;
    //     int cnt = 0;
    //     for (int i = 1; i <= n; i++) {
    //         a[i + n] = a[x];
    //         x--;
    //     }
    //     for (int i = 1; i <= 2*n; i++) {
    //         for (int j = i + 1; j <= 2*n; j++) {
    //             if (a[j] < a[i]) {
    //                 res++;
    //                 cnt++;
    //             } 
    //         }
    //     }
    //     for (int i = 1; i <= 2*n; i++) cout << a[i] << ' ';
    //     cout << endl;
    //     cout << cnt << endl;
    //     cout << endl;
    // } while (next_permutation(a + 1, a + n + 1));
    // cout << res << endl;
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
