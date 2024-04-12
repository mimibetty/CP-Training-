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
 
ll cnt[100005];
int a[100005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		int n;
 		cin >> n;
 		for (int i = 1;i <= n; i++) {
 			cin >> a[i];
 			cnt[a[i]]++;
 		}
 		ll res = 0 ;

 		for (int i = 1; i <= 100000; i++) {
 			if (cnt[i] == 0) continue;
 			// cout << i <<  ' ' << res << endl;
 			res += (cnt[i]*(cnt[i]-1)/2);
 			for (int j = 2; j*i <= 100000; j++) {
 				res += (cnt[i] * cnt[j*i]);
 			}
 		}
 		
 		cout << res << "\n";
 		for (int i = 1; i <= 100000; i++) cnt[i] = 0;
 	}
    return 0;
}