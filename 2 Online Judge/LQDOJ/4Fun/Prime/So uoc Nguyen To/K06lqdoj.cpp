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
 
 
bitset<20000005>Isprime;
vector<long long>multiPrime;

void sieve(int n) {
	for (int i = 2; i <= n; i++) Isprime[i] = 1;

	for (int i = 2; i * i <= n; i++) {
		if (Isprime[i] == 1) {
			for (int j = i * i; j <= n; j += i) {
				Isprime[j] = 0;
			}
		}
	}
} 

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	sieve(1e6);
	long long x = 1;

	multiPrime.pb(0);
	for (int i = 2;i <= 1e7; i++) {
		if (Isprime[i]) {
			if (x > 1e18/i) break;
			if (x * i > 1e18) break;
			
			if (x * i == 1e18) {
				x *= i;
				multiPrime.pb(x);
				break;
			}	
			else {
				x *= i;
				multiPrime.pb(x);
			}
		}
	}

	int t;
	cin >> t;
	
	sort(All(multiPrime));
	for (int z = 1; z <= t; z++) {
		long long n;
		cin >> n;

		long long res = 0;
		res = upper_bound(multiPrime.begin(),multiPrime.end(),n) - multiPrime.begin();
		res--;
		// cout << res << ' '<< multiPrime[res] << endl;
		cout << res << endl;
	} 
    return 0;
}