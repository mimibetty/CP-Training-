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
ll numDivisor[1000005];
ll res[1000005];
ll cnt[1000005];
int vt[1000005];
void sieve(int n) {
	for (int i = 2; i * i <= n ;i++) {
		if (trace[i] == 0) for (int j = i*i; j <= n; j+=i) {
			if (trace[j] == 0) trace[j] = i;
		}
	}

	for (int i = 2; i <= n; i++) if (trace[i] == 0) trace[i] = i;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	sieve(1000000);
    vector<int>s;

    //count num of divisor from 1>1e6
    numDivisor[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
    	int val = i;
    	ll num = 1;
    	while (val > 1) {
    		cnt[trace[val]]++;
    		if (cnt[trace[val]] == 1) s.pb(trace[val]);
    	 	val /= trace[val];
    	}
    	if (val != 1) {
    		cnt[val]++;
    		if (cnt[trace[val]] == 1) s.pb(trace[val]);
    	}
    	for (auto i : s) {
    		num *= (cnt[i]+1);
    		cnt[i] = 0;
    	}
    	numDivisor[i] = num;
    	s.clear();
    }
    
    res[0] = 0;
    for (ll i = 1; i <= 1000000; i++) {
    	res[i] = (numDivisor[i]-1)*i;
    	res[i] = max(res[i], res[i-1]);
    
    }

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n ;
    	cout << n + res[n] << '\n';
    }
    return 0;
}