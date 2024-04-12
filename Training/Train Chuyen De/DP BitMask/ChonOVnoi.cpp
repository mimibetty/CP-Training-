/*
link submit:  https://oj.vnoi.info/problem/qbselect
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

int a[5][10005];
int d[16];
long long dp[10005][16];
int bit(int n, int j) {
    return ((n >> j) & 1) ;
}
ll res = -3e8;

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i <= 15; i++) {
        d[i] = 1;
        for (int j = 0; j <= 2; j++) {
            if (bit(i,j) && bit(i,j + 1)) {
                d[i] = 0;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 16; i++) {
            if (d[i] == 1) {
                long long ans = -3e8;
                for (int i2 = 0; i2 < 16; i2++) {
                    if ((i2 & i) == 0) {
                        ans = max(ans , dp[j-1][i2]);
                    }
                }

                for (int vt = 0; vt < 4; vt++) {
                    if (bit(i, vt) == 1) {
                        ans += a[vt + 1][j];
                    }
                }
                dp[j][i] = ans;
                res = max(res, ans);
            }
        }
    }
    // for (int i = 0; i < 16; i++) {
    // }
    cout << res << endl;
    return 0;
}
