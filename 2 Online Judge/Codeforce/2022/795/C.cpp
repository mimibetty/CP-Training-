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
ll a[1000005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
       int n,k;
       cin >> n >> k;
       string s;
       cin >> s;

       s = ' ' + s;
       int one = 0;
       int val = 0;
       int one_first = -1, one_last = -1;
       for (int i = 1; i <= n; i++) {
          if (s[i] == '0') continue;

          one++;
          if (one_first == -1) one_first = i;
          one_last = i;
       }

       if (one == 0) {
        cout << 0 << endl;
        continue;
       }

       if (n - one_last <= k) {
            val++;
            one--;
            k -= (n - one_last);
       }

       if (one > 0 && one_first - 1 <= k) {
            one--;
            val += 10;
       }
       cout << val + one*11 << endl;
    
    }
    
    return 0;
}