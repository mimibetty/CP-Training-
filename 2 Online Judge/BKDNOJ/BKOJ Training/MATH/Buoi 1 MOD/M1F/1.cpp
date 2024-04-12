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
 
int a[105];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i =1 ; i <= n; i++) {
		cin >> a[i];
	}
	set<int>s;
	int gcd = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j <= n ;j++) {
			// gcd = __gcd(gcd,a[j]);
			gcd = __gcd(gcd,abs(a[j]-a[i]));
		}
	} 
	// for (auto i : s) cout << i << ' ';
  	s.insert(gcd);
    for (int i = 2; i <= sqrt(gcd); i++) {
    	if (gcd % i == 0) {
    		s.insert(i);
    		s.insert(gcd/i);
    	}
    }
    for (auto i : s) cout << i << ' ';
    return 0;
}