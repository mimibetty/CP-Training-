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
 
int trace[1000009]; // trace[i] là ước NT nhỏ nhất của i
int res[1000009];
// int a[1000005];

// faster
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	sieve(1000005);
 	vector<int> primes;
    for (int i = 1; i <= 1000005; i++) {
        if (i == trace[i]) primes.push_back(i);
    }

 	// for (int i = 1e6; i <= 1000005; i++) if (trace[i] == i) cout << i << endl;
 	for (int i = 1; i <= 1000000; i++) {
 		auto it = lower_bound(primes.begin(), primes.end(), i) - primes.begin();
        int val1 = primes[it];
        int val2 = 0;
        if (primes[it] != 2) it--;
        val2 = primes[it];

        if (abs(val1-i) >= abs(val2-i)) res[i] = val2;
        else res[i] = val1;
 	}
	// for (int i = 1; i <= 10; i++) cout << i << ' ' << res[i] << endl;
    // for (int i = 1; i <= 20; i++) cout << i << ' ' << trace[i] << ' '<< res[i] << endl;
 	
 	int t;	
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
        cout << res[n] << "\n"; 
    }
    return 0;
}