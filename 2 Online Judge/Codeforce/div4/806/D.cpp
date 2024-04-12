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

string s[100005];
void solve() {
    int n;
    cin >> n;
    map<string,int>d;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        d[s[i]] = 1;
    }
    // for (auto i : d) cout << i.fi << ' ' << i.se << endl;
  
    for (int z = 1; z <= n; z++) {
        // cout << s[z] << endl;
        bool ok = 0;
        int num = s[z].size();
        string s1,s2;
        for (int i = 0; i < num; i++) {
            s1 += s[z][i];
            for (int j = i+1; j < num; j++) {
                s2 += s[z][j];
            }
            // cout << z << ' ' << i << ' ' << s1 << ' ' << s2 << endl; 
            if (d[s1] == 1 && d[s2] == 1) {
                ok = 1;
                break;
            }
            s2.clear();
        }
        cout << ok ;
        // cout << endl;
    }
    // for (int i = 1; i <= n; i++) cout << s[i] << endl;
}
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
        solve();
        cout << endl;
    }
    return 0;
}