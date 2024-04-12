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
ll d[100005]; 
ll phi[100005]; 


long long pw(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(x, n / 2);
    if (n % 2 == 0) {
        return q * q % MOD;
    }
    else {
        return q * q % MOD * x % MOD;
    }
}

// faster
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (trace[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (trace[j] == 0) {
                    trace[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (trace[i] == 0) {
            trace[i] = i;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	vector<int>primes;
 	sieve(1e6);

    for (int i = 2; i <= 1e6; i++) {
        if (trace[i] == i) primes.push_back(i);
    }

    int t;
    cin >> t;
  
    while (t--) {
  
    	ll l,r;
    	int k;
    	cin >> l >> r >> k;

    	for (long long i = 1; i <= r-l+1; i++) {
	        d[i] = i+l-1;
	        phi[i] = i+l-1;
            // cout << i << ' ' << i+l-1 <<' ' << phi[i]<< endl;
    	}

    	for (auto i : primes) {
            ll firstnum = (l-1)/i * i + i;
            ll lastnum = r/i * i;
            for (auto j = firstnum; j <= lastnum; j += i) {
                if ( d[j - l + 1] % i == 0) {
                    // cout << "STT  :"  << i << endl; 
                	// cout << j << ' ' <<j - l + 1 << ' ' << d[j - l + 1] << endl;
                    phi[j - l + 1] -= phi[j - l + 1]/i;
                	while ( d[j - l + 1] % i == 0) {
	                    d[j - l + 1] /= i;
	                }
                    // cout << j << ' ' <<j - l + 1 << ' ' << d[j - l + 1] << endl; 	
                }
            }
    	}

        int cnt = 0;
    	for (long long i = 1; i <= r-l+1; i++) {
	        if (d[i] > 1) phi[i] -= phi[i]/d[i];
	        d[i] = 0;

            if (phi[i] % k == 0) cnt++;
            // cout << i+l-1 <<' ' <<phi[i+l-1] << endl; 
    	}

        precision(6);
        // for (int i = 1; i <= 10; i++) {
        //     cout << i << ' ' << i+l-1<< ' ' << d[i] << ' '<< phi[i] << endl; 
        // }
        cout << 1.000000*cnt/(r-l+1) << '\n';
            	
    }
    return 0;
}