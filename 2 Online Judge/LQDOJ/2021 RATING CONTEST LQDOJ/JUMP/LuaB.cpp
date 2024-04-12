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
 	
 	int n;
 	cin >> n;
 	vector<pair<ll,ll>>a,b;
 	map<long long,bool>d;
 	vector<long long>ar;

 	for (int i = 1; i <= n; i++) {
 		char c;
 		long long cuoc, point;
 		cin >> c;
 		cin >> point >> cuoc;
 		// cout << c << ' ' << point << ' ' << cuoc << endl;
 		if (d[point] == 0) ar.pb(point);
 		if (d[point+1] == 0) ar.pb(point+1);
 		if (d[point-1] == 0) ar.pb(point-1);
 		// cout << i << ' ' << point << ' ' << d[point] << ' '<<d[point+1] << ' ' <<d[point-1] << endl;
 		// for (auto i : ar) cout << i << ' ';
 		// cout << endl;

 		d[point+1] = 1;
 		d[point-1] = 1;
 		d[point] = 1;
 		if (c == 'A') a.pb({point,cuoc});
 		else b.pb({point,cuoc});
 	}
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
 	// for (auto i : ar) cout << i << ' ';

    int na = a.size();
    int nb = b.size();
    vector<long long>csa(na);
    vector<long long>csb(nb);
    vector<long long>psa(na);
    vector<long long>psb(nb);
    

    for (int i = 1; i <= na; i++) {
        csa[i] = a[i].fi;
        psa[i] = psa[i-1] + a[i].se;
    }


    for (int i = 1; i <= nb; i++) {
        csb[i] = b[i].fi;
        psb[i] = psb[i-1] + b[i].se;
    }


 	long long res = -1e18, cs = 0;
 	for (auto L : ar) {
 		long long sum1 = 0;
 		// for (auto j : a) {
 		// 	if (j.fi >= L) {
 		// 		sum1 -= j.se; 
 		// 	}
 		// 	else sum1 += j.se; 
 		// }

 		// for (auto j : b) {
 		// 	if (j.fi <= L) {
 		// 		sum1 -= j.se; 
 		// 	}
 		// 	else sum1 += j.se; 
 		// }
        auto q1 = lower_bound(csa.begin(),csa.end(),L)  - csa.begin();
        auto q2 = upper_bound(csb.begin(),csb.end(),L)  - csb.begin();
        
        sum1 += -psa[na] + 2*psa[q1-1];

        sum1 += psb[nb] - 2*psa[q2-1];
 		if (sum1 >= res) {
 			res = sum1;
 			cs = L;
 		}
 	}
	cout << cs << ' '<< res << endl;
    return 0;
}