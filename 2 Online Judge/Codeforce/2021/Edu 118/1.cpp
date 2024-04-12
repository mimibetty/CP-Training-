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
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
		string s1,s2;
		long long p1,p2;
		cin >> s1 >> p1;
		cin >> s2 >> p2;

		long long n1 = s1.size() , n2 = s2.size();
		if (n1 + p1 == n2 + p2) {
			bool check = 0;
			for (int i = 0; i < min(n1,n2); i++) {
				if (s1[i] > s2[i]) {
					check = 1;
					cout << '>' << endl;
					break;
				}
				else if (s1[i] < s2[i]) {
					check = 1;
					cout << '<' << endl;
					break;
				}
			}
			if (check == 0) {
				bool ok = 0;
				for (int i = min(n1,n2); i < max(n1,n2); i++) {
					if (s1[i] >= '1' && s1[i] <= '9') {
						ok = 1;
						cout << '>' << endl;
						break;
					}
					if (s2[i] >= '1' && s2[i] <= '9') {
						ok = 1;
						cout << '<' << endl;
						break;
					}
				}
				if (ok == 0) cout << '=' << endl;
			}  
		}
		else if (n1 + p1 > n2 + p2) cout << '>' << endl;
		else cout << '<' << endl;
 	}
    return 0;
}