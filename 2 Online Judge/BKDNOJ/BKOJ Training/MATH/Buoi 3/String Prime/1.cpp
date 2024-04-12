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
 
int trace[100005];

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i * i; j <= n; j+= i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	} 
	for (int i = 2; i <= n; i++) if(trace[i] == 0) trace[i] = i;
} 

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	sieve(100000);

 	int t;
 	cin >> t;
 	 
 	while (t--) {
 		string s;
 		cin >> s;
 		map<char,int>d;
 		int cnt = 0;
 		for (int i = 0; i < s.size(); i++) {
 			if (d[s[i]] == 0) cnt++;
 			d[s[i]]++;
 		}
 		bool check = 1;
 		for (char i = 'a'; i <= 'z'; i++) {
 			if (trace[d[i]] != d[i]) {
 				check = 0;
 				break;
 			}
 		}
 		if (trace[cnt] != cnt) check = 0;

 		if (check == 1) cout << "YES";
 		else cout << "NO";
 		cout << '\n';
 		d.clear();
 	}
    return 0;
}