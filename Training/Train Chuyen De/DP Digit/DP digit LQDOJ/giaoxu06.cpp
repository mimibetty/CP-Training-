/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
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

ll dp[31][1230];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        dp[1][i*2] = 1;
    }

    for (int i = 2; i<= n; i++) {
        for (int sum = 1; sum <= 1220; sum++) {
            if (dp[i-1][sum] == 0 ) continue; 
            for (int digit = 0; digit <= 9; digit++) {
                dp[i][sum + digit*2] += dp[i-1][sum];
            }
        }
    }

    
    for (int sum = 1; sum <= 1220; sum++) {
        if (dp[n][sum] == 0 ) continue; 
        for (int digit = 0; digit <= 9; digit++) {
            dp[n+1][sum + digit] += dp[n][sum];
        }
    }
    
    ll res = 0;
    for (int i = 10; i <= 1220; i +=10) {
        res += dp[n+1][i];
    }
    cout << res << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}