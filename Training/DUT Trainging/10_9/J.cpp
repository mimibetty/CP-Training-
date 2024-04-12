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

long long mul(long long a, long long b, long long m){
    if (b == 1) return a % m;
    if (b == 0) return 1 % m;
    a %= m; b %= m;
    long long q = mul(a, b / 2, m);
    if (b % 2 == 0) return ((q + q) % m + m) % m;
    else return ((q + q + a) % m + m) % m;
}
 
long long pw(long long a, long long n, long long m){
    if (n == 0) return 1 % m;
    long long q = pw(a, n / 2, m);
    if (n % 2 == 0) return mul(q, q, m);
    return mul(mul(q, q, m), a, m);
}
 
// Milner-Rabin algorithm
bool checkprime(long long n){
    if (n == 2) return 1;
    if (n % 2 == 0 || n == 1) return 0;
    long long m = n - 1;
    long long s = 0;
    while (m % 2 == 0){
        m /= 2; s++;
    }
    long long dem = 0, q = 0, a, b;
    while (dem <= 4){
        dem++;
 
        a = Rand(2, n - 2);
        b = pw(a, m, n);
 
        if ((b + 1) % n == 0 || (b - 1) % n == 0) {q++;continue;}
        for (int i = 1; i <= s; i++) {
            b = mul(b, b, n);
            if ((b + 1) % n == 0) {q++; break;}
        }
    }
    if (q == 5) return 1;
    return 0;
}
 
map<long long, long long> alpha;
 
void brute(long long n){
    if (n == 1) return;
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0) {
           while (n % i == 0) {alpha[i]++; n /= i;}
        }
    }
    if (n > 1){
        alpha[n]++;
    }
}
 
long long f(long long x, long long m){
    return (mul(x, x, m) + 1) % m;
}
 
long long findFactor(long long n){
    long long x = Rand(2, n - 1);
    long long y = x;
    long long p = 1;
    while (p == 1){
        x = f(x, n);
        y = f(f(y, n), n);
        p = __gcd(abs(x - y), n);
    }
    return p;
}
 
void fact(long long n){
    if (n == 1) return ;
    if (checkprime(n)) {alpha[n]++; return;}
 
    if (n <= 100000) {
        brute(n); return;
    }
    long long p = 0;
    while (p == 0 || p == n){
        p = findFactor(n);
    }
    fact(p); fact(n / p);
}

vector<long long>ts; 
void backtrack(int val, vector<pair<long long,int>>&a, long long res) {
    if (val == a.size()) {
        ts.pb(res);
        // cout << res << endl;
        return;
    }

    backtrack(val + 1, a, res);
    for (int i = 1; i <= a[val].se; i++) {
        res =  res * a[val].fi;
        // cout << i << ' ' << a[val] << ' ' << cnt[a[val]] << ' ' << res << endl;
        backtrack(val + 1, a, res);
    }
}   

void solve() {
    unsigned long long n;
    cin >> n;
    int limm = 1e7;
    vector<int>div;
    unsigned long long tmp = n;
    unsigned long long mul = 1;;
    
    for (int i = 2; i <= limm; i++) {
        while (tmp % i == 0) {
            tmp /= i;
            div.pb(i);
        }
    }
    bool ok = 1;
    if (div.size() < 4 || div.size() > 6) {
        cout << -1  << endl;
        return;
    }

    for (int i = 1; i < div.size(); i++) {
        if (div[i] == div[i-1]) {
            cout << -1 << endl;
            return;
            // break;
        }
    }

    for (auto i : div) mul *= i;
    if (div.size() == 6) {
        if (tmp == 1) for (auto i : div) cout << i << ' ';
        else cout << -1 << endl;
        // for (auto i : div) cout << i << ' ';
        return;
    }

    unsigned long long final = n / mul;
    // if (div.size() == 5) {
    //     if (mul <= limm)
    // }

    // if (div.size() == 4) {
    //     for (auto i : div) cout << i << ' ';
    //     return;
    // }
    alpha.clear();
    fact(final);
    vector<pair<long long,int>>a;
    if (alpha.size() == 6-div.size()) {
        bool okk = 1;
        for (auto i : alpha) {
            if (i.se != 1 || i.fi <= limm || checkprime(i.fi) == 0) {
                cout << -1 << endl;
                return;
            }
        }

        for (auto i : div) cout << i << ' ';
        for (auto i : alpha) {
            cout << i.fi << ' ';
        }
    }
    else {
        cout << -1 << endl;
        return;
    }
    // for (auto i: alpha){
    //     a.pb({i.first,i.second});
    //     cout << i.first << "^" << i.second << "\n";
    // }
    // backtrack(0,a,1);
    // sort(All(ts));
    // vector<long long>val;

    // for (int i = 0; i < (ts.size() - 1); i++) if ((ts[i] + 1) == ts[i+1]) val.pb(ts[i]);
    // // if (val.size() == 0) cout << -1 << endl;
    // // else {
    // //     for (auto i : val) cout << i << ' ';
    // //     cout << endl;
    // // }

    // ts.clear();
    // val.clear();

}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // long long zz = 1e6;
    // zz+=100;
    // for (long long i = zz; i >= 1; i--) {
    //     long long tmp = i;
    //     bool ok = 1;
    //     for (int j = 2; j <= sqrt(i); j++) {
    //         if (i % j == 0) {
    //             ok = 0;
    //             break;
    //         }   
    //     }
    //     if (ok == 1) {
    //         cout << i << endl;
    //         break;
    //     }
    // }
    // long long z = 1ll* 2 * 3 * 5 * 7 *11* 1000099*10000079;
    // cout << z << endl;
    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}