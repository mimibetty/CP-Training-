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
 
int trace[1000005];
vector<int>primes;

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i *i; j <= n; j+=i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	}

	for (int i = 2; i <= n; i++) if(trace[i] == 0) primes.pb(i);
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	sieve(1000000);

	int t;
	cin >> t;
	while (t--) {
		int d;
		cin >> d;

		ll res = 1;
		auto a = lower_bound(primes.begin(), primes.end(), d+1) - primes.begin();
		auto b = lower_bound(primes.begin(), primes.end(), primes[a] + d) - primes.begin();
		
		cout << primes[a] * primes[b] << endl;
	} 	
    return 0;
}