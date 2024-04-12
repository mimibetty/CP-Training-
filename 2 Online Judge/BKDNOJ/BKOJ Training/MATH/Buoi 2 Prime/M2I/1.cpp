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

ll pw(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	ll q = pw(a,b/2);
	if (b % 2 == 0) return q * q;
	else return q * q * a;
}


void sieve(int n) {
	for (int i = 2; i * i <= n ;i++) {
		if (trace[i] == 0) for (int j = i*i; j <= n; j+=i) {
			if (trace[j] == 0) trace[j] = i;
		}
	}

	for (int i = 2; i <= n; i++) if (trace[i] == 0) trace[i] = i;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	sieve(1000000);

	int n,q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >>a[i];
		cnt[a[i]]++;
	}

	while(q--) {
		int x;
		cin >> x;

		bool check = 0;
		bitset<7>bs;
		vector<int>s;
		int value = x;

		while (value > 1) {
			if (cnt2[trace[value]] == 0) s.pb(trace[value]);
			cnt2[trace[value]]++;
			value /= trace[value];
		}
		int num = s.size();

		int gcd;
		ll val;
		ll number;
		for (int bit = 0; bit < (1 << num); bit++) {
			bs = bit;
			if (cntBit(bit) != 2) continue;
			
			vector<int>fac;
			for (int j = 0; j < num; j++) {
				if (bs[j] == 1) fac.pb(s[j]);
			}

			for (auto j : fac) cnt2[j]--;
			
			gcd = 0;
			val = 1;
			for (auto j : s) {
				gcd = __gcd(gcd,cnt2[j]);
			}

			if(gcd == 0) {
				check = 1;
				break;
			} 
			
			for (auto j : s) {
				val *= pw(j, (cnt2[j]/gcd)); 
			}

			if (gcd == 1) {
				if (cnt[val] != 0) {
					check = 1;
					break;					
				}
			}
			else {
				for (int j = 1; j <= gcd; j++) {
					number = pw(val,j);
					if (cnt[number] != 0) {
						check = 1;
						break;
					}
				}
			}
			for (auto j : fac) cnt2[j]++;
			fac.clear();	
			if (check == 1) break;
		}


		for (auto e : s) {
			cnt2[e] -= 2;
			gcd = 0;
			val = 1;
			for (auto j : s) {
				gcd = __gcd(gcd,cnt2[j]);
			}	
			if(gcd == 0) {
				check = 1;
				break;
			} 
			for (auto j : s) {
				val *= pw(j, (cnt2[j]/gcd)); 
			}

			if (gcd == 1) {
			 	if ( cnt[val] != 0) {
					check = 1;
					break;
				}
			}
			else {
				for (int j = 1; j <= gcd; j++) {
					number = pw(val,j);
					if (cnt[number] != 0) {
						check = 1;
						break;
					}
				}
			}

			cnt2[e]+=2;
		}


		for (auto j : s) {
			cnt2[j] = 0;
		}
		s.clear();

		if (check == 1) {
			cout << "YES" << '\n';
		}
		else cout << "NO" << '\n';
	} 

    return 0;
}