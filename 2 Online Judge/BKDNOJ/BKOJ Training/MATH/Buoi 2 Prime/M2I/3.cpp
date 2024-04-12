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

int a[100005];
int cnt[1000005];
int cnt2[1000005];
int trace[1000005];

// ll pw(ll a, ll b) {
// 	if (b == 0) return 1;
// 	if (b == 1) return a;

// 	ll q = pw(a,b/2);
// 	if (b % 2 == 0) return q * q;
// 	else return q * q * a;
// }


void sieve(ll n) {
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

	int n,q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// cnt[1] = 1;
	for (int i = 1; i <= n; i++) {
		ll number = a[i];
		cnt[number] = 1;
		for (int j = 1; j <= 30; j++) {
			number *= a[i];
			if (number > 1000000) break;
			cnt[number] = 1;
		}
	}

	while(q--) {
		ll x;
		cin >> x;
		ll value = x;
		ll val = x;

		bool check = 0;
		vector<int>factor;

		while (value > 1) {
			if (cnt2[trace[value]] == 0) factor.pb(trace[value]);
			cnt2[trace[value]]++;
			value /= trace[value];
		}

		int num = factor.size();

		for (int i = 0; i < num; i++) {
			for (int j = i; j < num; j++) {
				val = x;

				val = val/factor[i];
				if (val % factor[j] == 0) val /= factor[j];
				else continue;
				if (cnt[val] > 0 || val == 1) {
					check = 1;
					break;
				}			
			}
		}

		for (auto j : factor) {
			cnt2[j] = 0;
		}
		factor.clear();
		
		if (check == 1)	cout << "YES" << '\n';
		else cout << "NO" << '\n';

	} 

    return 0;
}