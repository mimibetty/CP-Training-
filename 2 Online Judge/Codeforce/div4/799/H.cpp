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

vector<int>a[200005];
void solve() {
    int n;
    cin >> n;
    int x;
    set<int>s;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x].pb(i);
        s.insert(x);
    }
    
    int val = 0;
    pair<int,int>vt;
    // for (auto i : s) {
    //     cout << i << endl;
    //     for (auto j : a[i]) cout << j << ' ';
    //     cout << endl;  
    // } 
    // cout << endl;
      
    for (auto j : s) {
        int aa = j;
        int num = a[aa].size();
        
        int ff = 0;
        int l = a[aa][0],r;
        for (int i = 0; i < num; i++) {
            if (i - l + 1 a[aa][i] - a[aa][l] + 1 > ff) {
                ff = a[aa][i] - a[aa][l] + 1;
                r = i;
            }
            else {
                l = i;
            }
        }
        if (ff > val) {
            val = aa;
            vt = {l,r};
        }

    }
    cout << val << ' ' << a[val][vt.fi] << ' ' << a[val][vt.se] << endl;
    for (auto i : s) {
        a[i].clear();
    }
    s.clear();
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
    }
    return 0;
}