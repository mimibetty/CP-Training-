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

void solve() {
    vector<int>a;
    long long n;
    cin >> n;
    long long x = n;
    while (x > 0) {
        a.pb(x%2);
        x/=2;
    }
    a.pb(0);
    reverse(a.begin(),a.end());
    int dd = a.size();
    int cnt1 = 0;
    for (int i = 0; i < dd; i++) {
        if (a[i] == 1) cnt1++;
        // cout << a[i];
    }
    // cout << endl;
    
    int vt1 = -1;
    int vt0 = -1;
    long long res = 1;
    
    if (cnt1 == 1) {
        for (int i = dd - 1; i >= 0; i--) {
            if (a[i] == 1 && vt1 == -1) vt1 = i;
            if (a[i] == 0 && vt0 == -1) vt0 = i;
        } 
        vt1 = dd - vt1 - 1;
        vt0 = dd - vt0 - 1;
        long long res2 = 1; 
        for (int i = 1; i <= vt1; i++) res *= 2;
        for (int i = 1; i <= vt0; i++) res2 *= 2;
        
        cout <<res + res2;
    }
    else {
        for (int i = dd - 1; i >= 0; i--) {
            if (a[i] == 1 && vt1 == -1) vt1 = i;
        } 
        vt1 = dd - vt1 - 1;
        for (int i = 1; i <= vt1; i++) res *= 2;
        cout <<res;

    }
    
    cout << endl;
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
    while (t--) solve();
    return 0;
}