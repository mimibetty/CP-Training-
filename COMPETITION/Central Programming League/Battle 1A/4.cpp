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

long long rev[1000005];
long long dp[1000005];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<long long>v;
    for (int i = 1; i <= 1000000; i++) {
        long long val = 0;
        long long x = i;
        while (x > 0) {
            val = val * 10 + (x%10);
            x /= 10;
        }
        rev[i] = val;
    }


    for (int i = 1; i <= 1000000; i++) {
        // cout << "VT I:"  << i << endl;
        for (int j = 1; j <= 1000000; j++) {
            if (j == 1) {
                dp[j] = i;
                // cout << i << endl; 
            }
            else dp[j] = dp[j-1] + rev[dp[j-1]];
            // cout << j << ' '<< dp[j] << endl;;
            if (dp[j] > 1000000) break;
            v.pb(dp[j]);
        }
        // cout << endl << endl;
    }

    sort(v.begin(),v.end());
    
    int t;
    cin >> t;
    while (t--) {
        long long l,r;
        cin >> l >> r;
        auto right = upper_bound(v.begin(),v.end(), r) - v.begin();
        auto left = lower_bound(v.begin(),v.end(), l) - v.begin();
        cout << right - left <<endl;
    }
    return 0;
}