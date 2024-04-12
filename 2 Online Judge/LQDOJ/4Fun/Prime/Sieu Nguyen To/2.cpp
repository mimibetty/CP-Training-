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
 
 
bool check(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}

	return 1;

}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long a;
 	cin >> a;

 	string s = to_string(a);
 	bool ok = 1;

 	int n = s.size();
 	for (int i = 0; i < s.size(); i++) {
 		int cs = s[i] - '0';
 		if (i == 0) {
 			if (cs % 2 == 0 && cs != 2) {
 				ok = 0;
 				break;
 			}
 		}
 		else {
 			if (cs % 2 == 0) {
 				ok = 0;
 				break;
 			}	
 		}
 	}

 	if (ok == 0) {
 		cout << "KHONG";
 		return 0;
 	}

 	int x = 0;
 	for (int i = 0; i < n;i++) {
 		x *= 10;
 		x += s[i] - '0';
 		ok = check(x);
 		if (ok == 0) {
 			cout << "KHONG";
 			return 0;
 		}
 	}

 	cout << "PHAI";

    return 0;	
}