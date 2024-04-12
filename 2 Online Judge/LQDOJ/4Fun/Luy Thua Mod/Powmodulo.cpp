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
 
const long long MOD = (long long)1000000000000000009;

long long mul(long long a, long long b, long long p) {
    if (b == 0) return 0;
    long long c = mul(a, b / 2, p);
    if (b % 2 == 0) return (c + c) % p;  
    else return ((c + c) % p + a) % p;
}


long long pw(long long a, long long b, long long p) {
	if (b == 0) return 1;

	long long q = pw(a, b/2, p) % p;
	long long res = 1;
	if (b % 2 == 0) res = mul(q , q , p); // res = q%p * q%p
	else res =  mul(mul(q,q,p), a , p);  //res = q%p * q%p * a%p; 
	return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while(t--) {
 		long long a,b,c;
 		cin >> a >> b >> c;
 		long long d = pw(b,c, MOD - 1);
 		cout << pw(a,d, MOD) << endl;

 	}
    return 0;
}