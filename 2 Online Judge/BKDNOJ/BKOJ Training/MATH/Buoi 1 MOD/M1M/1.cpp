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
const ll MOD = ll(1e9)+7;
const double PI = acos(-1);
 
ll a[1000];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    a[1] = 1;
    a[2] = 6;
    ll res;
    // for (int i =3 ; i <= 10; i++) {
    // 	a[i] = ((2*a[i-1] - a[i-2] + 4) +MOD)%MOD;
    //     a[i] %=MOD;
    //  //    if (a[i-1] != (a[i] + a[i-2])/2 - 2) cout << i << ' '<< a[i] << ' '<< endl;
    //  //    ll num = i - 2;
    //  //    res = 6;
    //  //    res += (num%MOD * 5)%MOD;
    //  //    res %= MOD;
    //  //    res += (2*(num%MOD)*(num+1)%MOD)%MOD;
    //  //    res %=MOD;
    //  //    if (res != a[i]) cout << i << ' ' <<res << ' ' << a[i] << endl;
    // 	// cout << i << ' ' << a[i] << endl;
    // } 

 	int t;
 	cin >> t;
 	while (t--) {
 		ll n;
 		cin >> n;
 		res = 0;
 		if (n <= 2) cout << a[n];
 		else {
 			ll num = n - 2;
 			res = 6;
 			res += (num%MOD * 5)%MOD;
 			res %= MOD;
 			res += (2*(num%MOD)*((num+1)%MOD))%MOD;
 			res %=MOD;
 			cout << res;
 		}
 		cout << endl;
 	}
    return 0;
}