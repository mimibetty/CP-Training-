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
 
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int a[300005];
int b[300005];
int c[300005];

long long MOD = 1000000007;
long long combi2(long long n) {
    if (n < 2) return 0;
    if (n % 2 == 0) return (n/2) * (n-1) % MOD;
    else return n * ((n-1)/2) % MOD;
}

long long combi3(long long n) {
    if (n < 3) return 0;
    long long a = n;
    long long b = n-1;
    long long c = n-2;
    if (a % 3 == 0) {
        a /= 3;
    }
    else if (b % 3 == 0) {
        b /= 3;
    }
    else c/=3;

    if (a % 2 == 0) {
        a /= 2;
    }
    else if (b % 2 == 0) {
        b /= 2;
    }
    else c/=2;

    return a * b % MOD * c % MOD;    
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n; 
    cin >> n;

    int azero = 0, bzero = 0;

    map<pair<int,int>,int>d;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i] >> b[i] >> c[i];  // -a/b;
        
        if (a[i] == 0 && b[i] == 0) continue;

        if (a[i] == 0) {
            azero++;
            continue;
        }
        if (b[i] == 0) {
            bzero++;
            continue;
        }


        int x = __gcd(a[i],b[i]);
        
        a[i] /= x;
        b[i] /= x;
        
        d[{a[i], b[i]}]++;
    }

    long long res = 0;
    res += combi3(n);
    // cout << res << endl;

    for(auto i : d) {
        res -= combi2(i.se)*(n - i.se) % MOD;
        res = res % MOD + MOD;
        res %= MOD;
        // cout << i.fi.fi << ' ' << i.fi.se << ' ' << i.se << ' '<< combi2(i.se)*(n - i.se) << endl;
    } 
    // cout << res <<endl;

    res -= combi2(azero)*(n - azero) % MOD;
    res = res % MOD + MOD;
    res %= MOD;

    res -= combi2(bzero)*(n - bzero) % MOD;
    res = res % MOD + MOD;
    res %= MOD;



    for(auto i : d) {
        res -= combi3(i.se);
        res = res % MOD + MOD;
        res %= MOD;
    }
    res -= combi3(azero);
    res = res % MOD + MOD;
    res %= MOD;

    res -= combi3(bzero);
    res = res % MOD + MOD;
    res %= MOD;

    cout << res <<endl;
    return 0;
}   