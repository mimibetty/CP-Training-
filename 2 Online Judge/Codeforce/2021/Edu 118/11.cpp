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
 	while (t--) {
 		string s1,s2;
 		long long p1,p2;
 		cin >> s1 >> p1;
 		cin >> s2 >> p2;

 		if (p1 >= p2) {
 			p1-=p2;
 			p2 = 0;
 		}
 		else {
 			p1 = 0;
 			p2 -= p1;
 		}
 		for (int i = 1; i <= p1; i++) s1 += '0';
 		for (int i = 1; i <= p2; i++) s2 += '0';
 		

 		// cout << s1 << ' ' <<s2 << endl;
 		if (s1.size() > s2.size()) cout << '>';
 		else if (s1.size() < s2.size()) cout << '<';
 		else {
			bool ok = 0;
 			for (int i = 0 ; i < s1.size(); i++) {
 				if (s1[i] > s2[i]) {
 					ok = 1;
 					cout << '>';
 					break;
 				}
 				if (s1[i] < s2[i]) {
 					ok = 1;
 					cout << '<';
 					break;
 				}
 			}
 			if (ok == 0) cout << '=';
 		}
 		cout << endl;				
 	}
    return 0;
}