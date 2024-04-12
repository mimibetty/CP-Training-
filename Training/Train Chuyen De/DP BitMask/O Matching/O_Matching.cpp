/*
link submit: https://atcoder.jp/contests/dp/tasks/dp_o?lang=en
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

bool a[22][22];
const ll MOD = 1e9 + 7;
long long dp[1 << 21];
int n;
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    dp[0] = 1;
    for (int mask = 1; mask < (1 << n) ; mask++) {
        for (int i = 0; i < n; i++) {
            if (bit(mask, i) == 0) continue;
            for (int j = i + 1; j < n; j++)
        }
    }
    return 0;   
}