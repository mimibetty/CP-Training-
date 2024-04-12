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
const ll MOD = int(1e6)+3;
const double PI = acos(-1);
 
ll const MaxN = 1000008;
// int lim = 1000003; 
ll facto[MaxN];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	facto[0] = 1;
 	facto[1] = 1;
 	for (ll i = 1; i <= 1000003; i++) {
 		facto[i] = facto[i-1]%MOD * i%MOD;
 		facto[i] %= MOD;
 	}
 	// for (int i = 1; i <= 20; i++) cout << i << ' ' << facto[i] << endl;
 	int t;
 	cin >> t;
 	while (t--) {
 		// ans = n! x
 		ll n,x;
 		cin >> n >> x;
 		if (n >= MOD) cout << 0;
 		else cout << (facto[n]%MOD * x%MOD)%MOD;
 		cout << endl;
 	}
    return 0;
}