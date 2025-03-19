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

int a[1005];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "ON") {
            a[i] = 1;
        }
    }
    int start = 0;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            start = i;
            break;
        }
    }
    if (start == 0) {
        cout << start  << endl;
        return 0;
    }
    int res = 0;
    for (int i = n; i >= start; i--) {
        if (a[i] != a[i-1]) {
            res++;
        }
    }
    cout << res;
    return 0;
}

for (i = 1 -> n) {
    dp[pr[i].b] = max(max(dp[0]-> dp[pr[i].b]), prefixMax[pr[i].b]
    ,p[i] + max(dp[0]-> dp[pr[i].a - 1]), prefixMax[pr[i].a]-1]     )
}