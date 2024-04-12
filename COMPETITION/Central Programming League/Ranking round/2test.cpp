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

ll kg[105], val[105];
ll d[105][200005];
long long w,n,k;
bitset<22>bs;   

long long dp(int l, int r) {
   // cout << l << ' ' << r << endl;
    if (d[l][r] != -1) return d[l][r];

    if (l == 0 && r == 0) return d[l][r]  = 0;
    if (l == 0) return d[l][r] = 1e18;
    
    if (r - val[l] >= 0) {
        d[l][r] = min(dp(l-1, r - val[l]) + kg[l], dp(l-1, r) );
        return d[l][r];
    }
    
    return d[l][r] = dp(l-1,r );        
}

void sub3() {
    ll res = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 1e4; j++) {
            d[i][j] = -1;
        }
    }

    for (int j = 1; j <= 10000; j++) {
       if (dp(n,j) <= w) res = j;
    }
    cout << res ;
}


long long dpp[2000005];
void subcuoi() {
    for (ll i = 1; i <= w; i++) {
        for (ll j = 1; j <= n; j++) {
            dpp[i] = dpp[i-1];
            if (i - kg[j] >= 0) {
                dpp[i] = max(dpp[i],dpp[i - kg[j]] + val[j]);  
            } 
        }
    }
    ll xxx = 0;
    for (ll i = 0; i <= w; i++) xxx = max(xxx,dpp[i]);
    // for (int i = 0; i <= w; i++) cout << i <<' ' << dpp[i] << endl;
    cout << xxx << endl;
    return;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> w >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> kg[i] >> val[i];
    }

    subcuoi();

        return 0;
}