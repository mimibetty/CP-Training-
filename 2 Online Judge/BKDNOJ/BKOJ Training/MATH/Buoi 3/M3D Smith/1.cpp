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
int ps[10000005];

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i * i; j<= n; j+=i) if (trace[j] == 0) trace[j] = i;
		}
	}
	for (int j = 2; j <= n; j++) if (trace[j] == 0) trace[j] = j;

}

int sum(int n) {
	int val = 0;
	while (n > 0) {
		val += (n % 10);
		n/= 10;
	}
	return val;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	sieve(10000000);

	ps[1] = 1;

	for (int i = 2; i <= 10000000; i++) {
		int val1 = sum(i);
		int val2 = 0;

		int num = i;
		while (num > 1) {
			val2 += sum(trace[num]);
			num /= trace[num];
		}

		ps[i] = ps[i-1];
		if (val1 == val2) ps[i]++;
		// if (i <= 20) cout << i << ' ' << ps[i] << ' ' << val1 << ' '<< val2 << endl;
	}


	int t;
	scanf("%d", &t);

	while (t--) {
		int l,r;
		scanf("%d %d", &l, &r);
		printf("%d\n",ps[r] - ps[l-1]);

	}
    
    return 0;
}