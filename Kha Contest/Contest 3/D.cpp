/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
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
long double log_base_k(long double num, long double base) {
    long double res = log(num) / log(base);
    return res;
}

unsigned long long pw(long long a, long long b) {
    if(b == 0) return 1;
    unsigned long long q = pw(a,b/2);
    if (b % 2 == 0) return q*q;
    else return q * q * a;
} 

void solve1() {
    long long n;
    while(cin >> n) {
        if (n == 0) break;
        int res = 1;
        int ff = 1;
        // cout << n << endl;
        if (n < 0) ff = 2;
        long long nn = abs(n);  
        for (int i = 1; i <= 32; i+= ff) {
            long double base = i;
            long long x = log_base_k(nn,base);
            unsigned long long ff = pw(x,i);
            // cout << i << ' ' << x << ' ' << ff << endl;
            for (int j = -100; j <= 100; j++) {
                ll tmp = x + j;
                if (tmp <= 0) continue;

                unsigned long long z = pw(tmp,base);
                if (z > n) {
                    break;
                }
                if (z == nn) {
                    // cout << "herre we go   " << i << ' ' << tmp << ' ' << z << endl;
                    res = max(res, i);
                } 
            }
        }
        // EL;
        // cout <<n << endl;
        cout <<res <<endl;
    }
}

void solve() {
    ll n;
    while (cin >> n) {
        if (n == 0) return;
        vector<pair<int,int>>a;
        ll tmp = abs(n);

        for (int i = 2; i <= sqrt(abs(n)); i++) {
            if (tmp % i == 0) {
                int cnt = 0;
                while (tmp % i == 0) {
                    tmp /= i;
                    cnt++;
                }
                a.pb({i,cnt});
            }
        }
        if (tmp > 1) a.pb({tmp,1});
    
        int res = 0;       
        for (auto [u,v] : a) {
            res = __gcd(res,v);
        }

        if (n < 0) {
            int res2 = 1;
            for (int i = 1; i <= sqrt(res); i++) {
                if (res % i == 0) {
                    int zz = i;
                    if (zz % 2 == 1) {
                        res2 = max(res2, zz);
                    }
                    zz = res/i;
                    if (zz % 2 == 1) {
                        res2 = max(res2, zz);
                    }
                } 
            }
            cout <<res2 <<endl;
        } 
        else cout << res <<endl;
        // cout << res <<endl;
        // EL;
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
    return 0;
}