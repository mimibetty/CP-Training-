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
 
int trace[10000005];

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i * i; j <= n ; j+=i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	}

	for (int i = 2; i <= n; i++) if (trace[i] == 0) trace[i] = i;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	sieve(10000000);
 	// for (int i = 2; i <= 10; i++) cout << i << ' '<< trace[i] << endl;
 	int t;
 	cin >> t;
 	while (t--) {
 		int a,b;
 		cin >> a >> b;

 		set<int>s;
 		int x1 = a, x2 = b;
 		while (x1 > 1) {
 			int q1 = trace[x1];
 			s.insert(q1);
 			x1 /= q1;
 		}
 		while (x2 > 1) {
 			int q2 = trace[x2];
 			s.insert(q2);
 			x2 /= q2;
 		}
 		// for (auto i : s) cout << i << ' ';
 		// 	cout << endl;
 		cout << s.size() << '\n';
 		s.clear();
 	}
    return 0;
}