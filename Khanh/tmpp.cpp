/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

int rankz[500005];
int ps[500005];
void solve() {
    int n, c;
    long long p,q;
    cin >> n >> c >> p >> q;

    string s;
    cin >> s;
    s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1];
        if (s[i] == 'Y') {
            ps[i]++;
        }
        // cout << i << ' ' << ps[i] << endl; 
    }

    double pq = 1.000000*p/q;
    for (int i = 1; i <= n; i++) {
        int x = i - c + 1;
        bool ok = 0;
        if (x <= 0) continue;
        
        for (int z = 0; z <= 2*c; z++) {
            if (ok) break;
            int vt = x - z;
            if (vt <= 0) break;
            // cout << i << ' ' << vt << endl;
            if (rankz[vt] == rankz[i]) {
                // double tam = 1.00000*(ps[i] - ps[vt-1])/(i-vt+1);
                // cout << "TINH   " << tam << ' ' << ' ' << pq << endl;
                if (1LL * (ps[i] - ps[vt-1]) * q >= p * (i-vt+1)) {
                    ok = 1;
                    rankz[i+1] = rankz[i] + 1;
                    break;
                }
            } 
        }
        if (ok == 0) rankz[i+1] = rankz[i];
    }

    // for (int i = 1; i <= n + 1; i++) {
    //     cout << rankz[i] << ' ';
    // }
    cout << rankz[n+1];
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();
    
    return 0;
}

rseEy-lguqaS6B5BD_HPqg%3D%3D



ai == 0 
for i 1 -> m
    dp[vt][i] = dp[vt-1][i]  + dp[vt-1][i+1] + dp[vt-1][i-1]