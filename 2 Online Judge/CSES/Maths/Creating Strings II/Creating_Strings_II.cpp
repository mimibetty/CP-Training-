/*
link submit: 
Note:  res = n! / (cnt[a]!   * cnt[b]! *.... * cnt[z]!)

x/cnt[a]!  = x * pw(cnt[a], mod-2, mod) (fermat small) 
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

const long long MOD = 1e9 + 7;
const int NN = int(1e6 + 5);
long long fact[NN];
long long pw(long long a, long long b) {
    if (b == 0) return 1;
    long long q = pw(a,b/2);

    if (b % 2 == 0) {
        return q * q % MOD;
    }
    else {
        return q * q % MOD * a % MOD;
    }
}

long long inv(long long a) {
    return pw(a, MOD - 2);
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    map<char,int>d;

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= NN; i++) fact[i] = fact[i-1] * i % MOD;

    for (char i : s) {
        d[i]++;
    }

    long long res = fact[n];
    for (auto [key, val]: d) {
        // cout << key << ' ' << val << endl;
        res = res * inv(fact[val]) % MOD;
    }
    cout << res << endl;
    return 0;
}