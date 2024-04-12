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
 
 
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);	
    cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int vt0 = -1;
		int vt1 = -1;
		int cnt = 0;
		bool check = 1;

		for (int i = 0; i < (s.size()-1); i++) {
			if (s[i] > s[i+1]) {
				check = 0;
				break;
			}
		}

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') vt0 = i;
			if (s[i] == '1' && vt1 == -1) vt1 = i;
			if (s[i] == '1') cnt++;
		}

		if (check == 1) cout << 0 << endl;
		else {
			cout << 1 << endl;
			vector<int>a;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '1' && i < (s.size() - cnt)) a.pb(i+1);
				if (s[i] == '0' && i >= (s.size() - cnt)) a.pb(i+1);
			}

			cout << a.size() << ' ';
			for (auto i : a) cout << i << ' ';

			cout << endl;	
			a.clear();
			// for (int i = vt1; i < s.size(); i++) cout << i + 1 << ' ';
			// cout << endl; 
		}
	} 
    return 0;
}