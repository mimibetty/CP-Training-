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
 
struct ice{
	ll calo , hapy;
};

bool cmp(ice a, ice b) {
	if (a.calo == b.calo) {
		return a.hapy > b.hapy;
	}
	else return a.calo < b.calo;
}

ice a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
 	int t;
 	cin >> t;

 	while (t--) {
	 	int n,k;
	 	cin >> n >> k;

	 	for (int i = 1; i <= n; i++) {
	 		cin >> a[i].calo;
	 	}
	 	for (int i = 1; i <= n; i++) {
	 		cin >> a[i].hapy;
	 	}
	 	sort(a+1, a+1+n,cmp);

	 	ll mincalo = a[k].calo;
	 	ll sumhapy = 0;
	 	vector<ll>x;

	 	for (int i = 1;i <= n; i++) {
	 		if (a[i].calo <= mincalo) x.pb(a[i].hapy);
	 		else break;
	 	}
	 	// cout << mincalo << endl;
	 	sort(x.begin(), x.end());


	 	// for (int i = x.size() - 1; i >= (x.size() - k); i--) {
	 		// sumhapy += x[i];
	 		// cout << x[i] << endl;	
	 	// }

	 	int num = x.size();
	 	for (int i = num-k; i < num; i++) {
	 		sumhapy += x[i];
	 		// cout << x[i] << endl;	
	 	}

		x.clear();	 		

	 	cout << mincalo << ' '<< sumhapy << '\n';
 	}
    return 0;

}