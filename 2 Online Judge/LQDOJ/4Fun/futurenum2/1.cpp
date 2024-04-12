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

bool check(int n) {
	// n = p * q * r , min(p,q,r) < can bac 3 cua n 
	if (Isprime[n] == 1 || n == 1) return 0;

	int p = -1;
	if (n % 2 == 0) p = 2;
	else {
		for (int i = 3; i * i * i <= n; i+=2) {
			if (n % i == 0) {
				p = i;
				break;
			}
		}
	}

	if (p == -1) return 1;
	else {
		int q = n /p;
		if (Isprime[q] == 1) return 1;
		return 0;
	}
}
int main() {

    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

	
	sieve(20000000);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++) {
    	int a;
    	cin >> a;
    	if (check(a)) res++;
    }

    cout << res << endl;
    return 0;
}