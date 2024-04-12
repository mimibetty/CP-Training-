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
    while (dem <= 3){
        dem++;
 
        a = Rand(2, n - 2);
        b = pw(a, m, n);
 
        if ((b + 1) % n == 0 || (b - 1) % n == 0) {q++;continue;}
        for (int i = 1; i <= s; i++) {
            b = mul(b, b, n);
            if ((b + 1) % n == 0) {q++; break;}
        }
    }
    if (q == 4) return 1;
    return 0;
}
 
map<long long, long long> alpha;
 
void brute(int n){
    if (n == 1) return;
    for (int i = 2; i * i <= n; i++){
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
 
    if (n <= 10000) {
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
    int n;
    cin >> n;
    int tmp = n;
    vector<int>a;
    map<int,int>d;
    a.pb(n);
    int c = 0;
    while (tmp > 1) {
        int pre = tmp;
       
        int x = sqrt(tmp);
        bool ok = 0;
        vector<int>div;
        for (int i = 2 ; i <= x; i++) {
            if (tmp % i == 0) {
                div.pb(i);
                if (i*i != tmp) div.pb(tmp/i);
            }
        }

        sort(All(div));
        // cout << "DDIDD" << endl;;
        // for (auto i : div) cout << i << ' ';
        // EL;
        int len = div.size();
        for (int i = len - 1 ; i >= 0; i--) {
            if (tmp % div[i] == 0) {
                if (d[div[i]] == 2) continue;
                if (checkprime(tmp - div[i]) == 1) continue;
                tmp -= div[i];
                a.pb(tmp);
                d[div[i]]++;
                ok = 1;
                // cout <<"s1    " << i << ' '<<tmp << ' '<< div[i] << endl;
                break;
            }

        }
        if (ok == 1 || tmp == 1) continue;
        // bien thanh snt
        for (int i = len - 1 ; i >= 0; i--) {
            if (tmp % div[i] == 0) {
                if (d[div[i]] == 2) continue;
                tmp -= div[i];
                a.pb(tmp);
                d[div[i]]++;
                ok = 1;
                // cout <<"s2   " << i << ' '<<tmp << ' '<< div[i] << endl;
                break;
            }
        }
        if (ok == 1 || tmp == 1) continue;
        a.pb(tmp - 1);
        tmp -= 1;
        c++;
        // cout << "ss33   " << endl;
        // cout << tmp << endl;
        if (pre == tmp) {
            break;
        }
    }

    cout << a.size() << endl;
    for (auto i : a) cout << i << ' ';

    EL;
     ts.clear();
     alpha.clear();
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
    while(t--)
    solve();
    
    return 0;
}