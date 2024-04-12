#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
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
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
 
long long Rand(long long l, long long r){
    uniform_int_distribution<long long> rnd(l,r);
    return rnd(gen);
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

bool check(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}

	return 1;

}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long a;
 	cin>>a;

 	bool ok = 1;
 	while (a > 0) {
 		if (a >= 1e5) ok = checkprime(a);
 		else ok = check(a);
 		if (ok == 0) break;
 		a/=10;
 	}

 	if (ok) cout << "PHAI";
 	else cout << "KHONG";
    
    return 0;
}