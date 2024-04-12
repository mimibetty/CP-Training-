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
 
bool check(long long mid, long long chan , long long le , long long k) {
	if (mid % 2 == 0) {
		if (chan >= (mid/2)*k) return 1;
		return 0;
	}
	else {
		if (mid == 1) {
			if (le + chan*2 >= k) return 1;
			return 0;
		}
		if (chan >= (mid/2)*k) {
			long long cc = chan - ((mid/2)*k);
			le += cc * 2;
			if (le >= k) return 1;
			return 0;
		}
		return 0;
	}
}
void solve() {

	vector<int>cnt(50);
	long long n,k;
	cin >> n >> k;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}

	long long chan = 0, le = 0;
	for (int i = 0; i <= 35; i++) {
		chan += cnt[i]/2;
		le += cnt[i]%2; 
	}
	// cout << chan << ' ' << le << endl;
	// for (int i = 0; i <= 35; i++) cout << i << ' ' << cnt[i] << char(i+'a');
	long long lower = 1, uper = 1e9;
	long long mid;
	while (lower < uper) {
		mid = (lower + uper+1) /2;
		if (check(mid, chan , le , k) == 1) {
			lower = mid;
		}
		else uper = mid-1;
	}


		// cout << lower << ' ' << uper << ' ' << mid << ' ' << check(mid, chan , le , k) << endl;
	// for (int i = 1; i <= 10; i++) cout << i << ' ' << check(i,chan,le, k) <<endl;
	// cout << check(1,chan,le, k);

	// cout <<chan << ' ' <<le << endl;
	// cout << check(5, chan , le , k);
	cout << lower <<endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t; 
 	while (t--) {
 		solve();
 	}
    return 0;
}