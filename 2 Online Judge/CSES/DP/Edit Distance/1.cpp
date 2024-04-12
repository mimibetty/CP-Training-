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
 
string s1,s2;

ll d[10005][10005];
ll dp(string &s1, string &s2, long long vt1, long long vt2, long long &res) {
	if (vt2 == s2.size()) return res;
	if (vt1 == s1.size() + s2.size()) return 1e18;

	if (s1[vt1] == s2[vt2]) return dp(s1, s2, vt1 + 1, vt2 + 1, res + 1);
	
	auto a = dp(s1, s2, vt1, vt2 + 1, res + 1); // add 
    auto b = dp(s1, s2, vt1 + 1, vt2, res); // remove    
    auto c = dp(s1, s2, vt1 + 1,vt2 + 1, res + 1); // replace

    return min({a , b , c });
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> s1 >> s2;
 	ll n1 = s1.size(), n2 = s2.size();
 	ll vt1 = 0, vt2 = 0;

 	ll res = 0;
 	cout << dp(s1, s2, 0 , 0 , 0);
    return 0;
}