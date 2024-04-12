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

unsigned long long a[1000005],ps[1000005];

auto check(ll l, ll r) {
    auto rr = 0;
    for (ll i = l; i <= r; i++) rr = (rr^a[i]);
    return rr;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
        
        // cout << (0 ^ 6) << endl;
    int n ;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // ps[i] = a[i];
        ps[i] = (ps[i-1] ^ a[i]);
    }


    for (int i = n+1; i <= 1000000; i++) {
        a[i] = (ps[i-1] ^ ps[i - n - 1]);
        ps[i] = (ps[i-1] ^ a[i]);
        // ps2[i] = (ps2[i-1] ^ a[i]) ^ ;
        // if (i <= 10) {
        //     cout << i << ' ' << a[i] << ' ' << ps[i] << endl;
        // }
    }
    // for (int i = 1; i <= 10; i++) {
    //     cout << i <<' ' <<a[i] << ' ' << ps[i] << endl;
    // }

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        unsigned long long l,r;
        cin >> l >> r;
        r %= (n+1);
        l %= (n+1);
        r += n;
        l += n;
        r++;
        l++;
        cout << (ps[r] ^ ps[l-1])  <<  endl;
        // cout << (ps[r%n]^ps[l-1 % ]) << endl;

    }

    // cout << check(6,6); 
    // EL;
    // for (int i = 1; i <= 4*n; i++) cout << i << ' ' << a[i] << endl;
    return 0;
}