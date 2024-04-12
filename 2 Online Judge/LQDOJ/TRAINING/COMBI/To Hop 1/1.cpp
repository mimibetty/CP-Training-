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

int t,m; 
long long combi[1005][1005];
long long fact[100005], inv[100005]; 
int vp[100005];

long long pw(long long a, long long b) {
	if (b == 0) return 1;

	long long q = pw(a, b/2) % m;
	long long res = 1;

	if (b % 2 == 0) res = q * q % m;
	else res = q * q % m * a % m;

	return res;
}

void sub1() {
	combi[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (j == 0) combi[i][j] = 1 % m;
			else {
				combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
				combi[i][j] %= m;
			} 
		}
	}
}


long long combisub2(long long n, long long k) {
	if (k > n) return 0;
	return fact[n] * inv[k] % m * inv[n - k] % m;
}

void sub2() {
	fact[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		fact[i] = fact[i-1] * i % m;
	} 
	inv[100000] = pw(fact[100000], m-2);
	for (int i = (100000 - 1); i >= 1; i--) inv[i] = inv[i+1] * (i+1) % m; 

	while (t--) {
		long long n,k;
		cin >> n >> k;
		cout << combisub2(n,k) << endl;
	}
}

long long combisub3(long long n, long long k) {
	if (n < k) return 0;
	else {
		if (vp[n] > vp[k] + vp[n-k]) return 0;
		else return fact[n] * inv[k] % m * inv[n-k] % m;
	}
}

void sub3() {
	fact[0] = 1;
	inv[0] = 1;

	for (int i = 1; i <= 100000; i++) {
		vp[i] = vp[i-1];
		int val = i;
		while (val % m == 0) {
			val /= m;
			vp[i]++;
		} 
		fact[i] = fact[i-1] * val % m;
		inv[i] = pw(fact[i], m-2);
	}

}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> t >> m;

 	if (m == (long long)1e9 + 7) {
 		sub2();
 		return 0;
 	}
 	else {
 		sub3();
	 	sub1();
 	}

 	while (t--) {
 		long long n,k;
 		cin >> n >> k;

 		if (n <= 1000 && k <= 1000) {
 			cout << combi[n][k] << endl;
 			continue;
 		}
 		else {
 			cout << combisub3(n , k) << endl;
 		}
 	}
    return 0;
}