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

char af[300];
int n,k;
string s;

void solve() {
   cin >> n >> k;
   cin >> s; 

   for (int i = 0; i <= 30; i++) af[i] = '.';
   for (int i = 0  ; i < n; i++) {
        if (af[s[i] - 'a'] != '.') s[i] = char(af[s[i] - 'a']);


        if (s[i] == 'a') continue;
        char x = s[i];
        while (k > 0 && s[i] != 'a') {
            k--;
            s[i] = s[i] - 1;
            if (af[s[i] - 'a'] != '.') s[i] = char(af[s[i] - 'a']);
        }

            for (int j = s[i] - 'a' ; j <= x - 'a'; j++) {
                af[j] = s[i];
            }
   }

   cout << s << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    // for (char i = 'a' ; i <= 'z'; i++) cout << i << ' '; 
    return 0;
}