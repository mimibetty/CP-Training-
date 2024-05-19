/*
link submit: 
Note:
solution https://usaco.guide/problems/cses-2182-divisor-analysis/solution
https://www.youtube.com/watch?v=__21DNroCLo&ab_channel=NeatlyStructured
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

pair<long long , long long> a[100005];
int n;
const long long MOD = 1e9 + 7;

long long pw(long long a, long long b) {
    if (b == 0) return 1;
    long long q = pw(a, b/2);

    long long res = 1;
    if (b % 2 == 0) {
        res = q * q % MOD;
    }
    else {
        res = q * q % MOD * a % MOD;
    }
    return res;
}

long long modular_exponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);


    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    
    // cal number div
    long long number_div = 1;
    for (int i = 1; i <= n; i++) {
        number_div = number_div * (a[i].se + 1) % MOD;
    }
    // cout << "number div:   " << number_div << endl; 



    // // calc sum  
    //   gọi si là tổng khi tính giá trị của a[1] -> a[i]
    //   si =  s(i-1) * tổng(cấp số nhân a[i]^0 -> a[i]^a[i].se)
    
    long long div_sum = 1;
    for (int i = 1; i <= n; i++) {
        div_sum = div_sum * (pw(a[i].fi, a[i].se + 1) - 1) % MOD *
                  pw(a[i].fi - 1, MOD - 2) % MOD;
    }
    // cout << "div sum  " << div_sum << endl;



    //calc product 
    long long div_product = 1;
    bool odd = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].se % 2 == 1) {
            odd = 1;
            break;
        }
    }
    // 
    if (odd == 1) {
        long long mu = 1;
        for (int i = 1; i <= n; i++) {
            if (odd == 1 && a[i].se % 2 == 1) {
                mu = mu * ((a[i].se + 1)/2) % (MOD - 1);
                odd = 0;
            }
            else {
                mu = mu * ((a[i].se + 1)) % (MOD - 1);
            }
        }        

        for (int i = 1; i <= n; i++) {
            div_product = div_product * modular_exponentiation(a[i].fi , a[i].se * mu % (MOD - 1), MOD) % MOD ;
        }
    }
    else {
        long long mu = 1;
        for (int i = 1; i <= n; i++) {
            mu = mu * ((a[i].se + 1)) % (MOD - 1);
        }        

        for (int i = 1; i <= n; i++) {
            div_product = div_product * modular_exponentiation(a[i].fi , (a[i].se/2) * mu % (MOD - 1), MOD) % MOD;
        }
    }   
    // cout << "product  " << div_product << endl;



    cout << number_div << ' ' << div_sum << ' ' << div_product << endl;
    return 0;
}