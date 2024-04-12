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

long long dp[101][101][101];
long long a[105];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++ ) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    map<int,int>d;
    for (int i = 1; i <= n; i++) {
        d[a[i]] = i;
    }
    // for (auto i : d) cout <<i.fi << ' ' << i.se << en
    for (int i = 1; i <= n; i++) dp[i][i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int step = 0; step < n; step++) {
                for (int z = i ; z <= j; z++) {
                    if(__gcd(a[j], a[z]) == 1) {
                        dp[i][j][step + 1] += dp[i][z][step];
                        dp[i][j][step] %= 2023;
                    }
                }
            }
        }
    }

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int u,v,k;
        cin >> u >> v >> k;
        cout << dp[d[u]][d[v]][k];
    }    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (dp[i][j][k] > 0) cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
            }
        }
    }
    return 0;
}