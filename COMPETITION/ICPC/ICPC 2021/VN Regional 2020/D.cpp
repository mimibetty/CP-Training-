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
 
void solve(int n) {
	map<ll,int>d;
	ll x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		d[x]++;
	} 
	vector<ll>a(n+5);
	a[1] = 1;

	for (int i = 1; i <= n; i++) {
		// cout << i << ' ' << a[i] << endl;
		d[a[i]]--;
		if (d[a[i]] < 0) {
			cout << "NO" <<endl;
		
			return;
		}

		if (i == n) {
			if (d[a[i]] != 0) {
				cout << "NO" << endl;
				return;
			}
			continue;
		}	

		if (a[i] % 2 == 1) {
			if (d[a[i]*2] > 0) {
				a[i+1] = a[i]*2;
			} 
			else if(d[a[i] * 3] > 0) {
				a[i+1] = a[i] * 3;
			}
			else {
				cout << "NO" <<endl;				
				return;
			}
		}
		else {
			if (d[a[i]*2] > 0) {
				a[i+1] = a[i]*2;
			} 
			else if (d[a[i]/2] > 0) {
				a[i+1] = a[i]/2;
			} 
			else if(d[a[i]*3] > 0) {
				a[i+1] = a[i] * 3;
			}
			else {
				cout << "NO" <<endl;
				return;
			}	
		}

	}
	for (auto i : d) if (i.se != 0) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	EL;

}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	while (cin >> n && n != 0) {
 		solve(n);
 	}
    return 0;
}