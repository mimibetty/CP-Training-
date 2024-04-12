#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

long long dp[40005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    // string s = to_string(5);
    // cout << s << endl;
    vector<int>a;
    dp[0] = 1;

    for (int i = 1; i <= 4e4; i++) {
        string dd = to_string(i);
        string dd2 = dd;
        reverse(dd2.begin(),dd2.end());
        if (dd2 == dd) a.pb(i);
    }

    for (int i = 0; i < a.size(); i++) {
        for (int weigh = 1; weigh <= 4e4; weigh++) {
            if(weigh - a[i] >= 0) dp[weigh] += dp[weigh - a[i]];
            dp[weigh] %= MOD;
        }
    }

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;;
    }
    return 0;
}