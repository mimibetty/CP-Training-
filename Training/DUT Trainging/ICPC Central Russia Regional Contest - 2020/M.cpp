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

const ll modd = 1e9 + 7;
ll combi2(ll n) {
    if (n % 2 == 0) {
        return (n/2)*(n-1);
    }
    else return ((n-1)/2) *n;
}
// void solve() {
//     ll n;
//     cin >> n;
//     // if (n == 1) {
//     //     cout << 1 << endl;
//     //     return;
//     // }
//     // if ()
//     ll s = 0;
//     for (int i = 0; i <= n; i++) {
//         // s += max(1ll*0, n - 2*i);
        
//         // cout << i << ' ' << max(1ll*0, combi2(n- 2*i - 2)) << endl;
//         s += max(1ll*0, combi2(n- 2*i +1));
//     }
//     cout <<s <<endl;
// }

// ll dp[3000][6000];
// void solve() {
//     ll n;
//     cin >> n;
//     dp[0][n] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int j = -i; j <= i ; j++) {
//             dp[i][j + n] += dp[i-1][n + j-1] + dp[i-1][n + j]*2 + dp[i-1][n + j+1]; 
//             dp[i][j + n] %= modd;
//         }
//     }

//     ll s = 0;
//     for (int i = 1; i <= n; i++) {
//         s += dp[n][i+n];
//         s %= modd;
//     }
//     cout << s << endl;
// }

ll dp1[100009];
ll dp2[100009];

void solve2() {
    ll n;
    cin >> n;
    dp2[n] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = -i; j <= i ; j++) {
            dp1[j + n] = dp2[n + j-1] + dp2[n + j]*2 + dp2[n + j+1]; 
            dp1[j + n] %= modd;
        }
        for (int j = -i; j <= i ; j++) {
            dp2[j + n] = dp1[j+n]; 
        }
    }

    ll s = 0;
    for (int i = 1; i <= n; i++) {
        s += dp2[i+n];
        s %= modd;
    }
    cout << s << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while(t--)
    solve2();
    
    return 0;
}