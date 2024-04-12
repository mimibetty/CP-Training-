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

long long fact[100005], inv[100005]; 
int vp[100005][100];
vector<int>snt;
int sl = 0;
int phi;

long long pw(long long a, long long b, long long m) {
	if (b == 0) return 1;

	long long q = pw(a, b/2, m) % m;
	long long res = 1;

	if (b % 2 == 0) res = q * q % m;
	else res = q * q % m * a % m;

	return res;
}

long long combi(long long n, long long k) {
    if (n < k || k < 0) return 0;
	else {
		long long res = fact[n] * inv[k] % m * inv[n - k] % m;
		for (int i = 0; i < sl; i++) {
	        if (vp[n][i] > vp[k][i] + vp[n - k][i]) {
	            res *= pw(snt[i], vp[n][i] - vp[k][i] - vp[n - k][i], m);
	            res %= m;
	        }
		}
		return res;
	}
}

void solve() {
	fact[0] = 1 % m;
	inv[0] = 1 % m;

	for (int i = 1; i <= 100000; i++) {
		int val = i;
		
		for (int j = 0; j < sl; j++) {
			vp[i][j] = vp[i-1][j];
			
			while (val % snt[j] == 0) {
				val /= snt[j];
				vp[i][j]++;
			}
		}

		fact[i] = fact[i-1] * val % m;
		inv[i] = pw(fact[i], phi - 1, phi);
	}

}

int EulerPhi(int n) {
	long long res = n;
	int val = n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (val % i == 0) {
			res -= val/i;
			while(val % i == 0) val /= i;
		}
	}

	if (val > 1) res -= res/val;
	return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> t >> m;
 	int x = m;
 	phi = EulerPhi(m);

 	for (int i = 2; i <= sqrt(m); i++) {
 		if(x % i == 0) {
 			snt.pb(i);
	 		while(x % i == 0) x /= i;
 		}
 	}
 	if (x > 1) snt.pb(x);
 	sl = snt.size();
 	
 	solve();

 	while (t--) {
 		long long n,k;
 		cin >> n >> k;
 		cout << combi(n,k) << endl; 		
 	}


    return 0;
}