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
 
int cnt[300];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		string s;
 		cin >> s;
 		string b;
 		cin >> b;
			int n = s.size();
 		sort(s.begin(),s.end());
		for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
 		if (b == "abc" && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {

 			for (int i = 1; i <= cnt[0]; i++) cout << 'a';
 			for (int i = 1; i <= cnt[2]; i++) cout << 'c';
 			for (int i = 1; i <= cnt[1]; i++) cout << 'b';
 			for (int i = 3; i <= 30; i++) {
 				for (int j = 1; j <= cnt[i]; j++) cout << char(i+'a');
 			}

 			cout << endl;
 			// cout << s << endl;
 		}
 		else cout << s << endl;
		for (int i = 0; i <= 35; i++) cnt[i] = 0;
 	}
    return 0;
}