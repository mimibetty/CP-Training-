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
long long Rand(long long l, long long r){
    uniform_int_distribution<long long> rnd(l,r);
    return rnd(gen);
}

bool brute(long long n){
    if (n < 2) return 0;
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
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
    if (n <= 100) return brute(n);

    long long m = n - 1;
    long long s = 0;
    while (m % 2 == 0){
        m /= 2; s++;
    }
    long long dem = 0, q = 0, a, b;
    while (dem <= 1){
        dem++;
 
        a = Rand(2, n - 2);
        b = pw(a, m, n);
 
        if ((b + 1) % n == 0 || (b - 1) % n == 0) {q++;continue;}
        for (int i = 1; i <= s; i++) {
            b = mul(b, b, n);
            if ((b + 1) % n == 0) {q++; break;}
        }
    }
    if (q == 2) return 1;
    return 0;
}
 

void none(){
    cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 <<endl;
}

void solve(long long n) {
    if (n < 8) {
        none();
        return;
    }    

    long long a,b,c,d;
    long long sum;

    for (long long i = n - 6; i >= 1; i--) {
        if (checkprime(i)) {
            d = i;
            break;
        }
    }

    if ((n + d) % 2 == 0) c = 2;
    else c = 3;

    sum = n - d - c;

    for (long long i = 2; i <= sum - 2; i++) {
        if (checkprime(i) && checkprime(sum-i) ) {
            a = i;
            b = sum - i;
            break;
        }
    }
    cout << a << ' ' << b << ' ' << c << ' ' << d <<endl;

}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    for (int z = 1; z <= tt; z++) {
        long long n;
        cin >> n;
            // cout << n <<endl;
        // cout << z << ' ';      
         solve(n);
    }
    return 0;
}