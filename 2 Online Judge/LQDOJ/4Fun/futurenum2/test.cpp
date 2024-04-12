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
 

int cnt[20000005];
int trace[20000005];
vector<int>s;

void sieve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i * i; j <= n; j+=i) {
                if (trace[j] == 0) trace[j] = i;
            }      
        }
    }

    for (int i = 2; i <= n; i++) if (!trace[i]) trace[i] = i;
}


void backtrack(int val, vector<int>&a, int res) {
    if (val == a.size()) {
        s.pb(res);
        // cout << res << endl;
        return;
    }

    backtrack(val + 1, a, res);
    for (int i = 1; i <= cnt[a[val]]; i++) {
        res =  res * a[val];
        // cout << i << ' ' << a[val] << ' ' << cnt[a[val]] << ' ' << res << endl;
        backtrack(val + 1, a, res);
    }
}   


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int res = 0;
 	int n;
 	cin >> n;

 	sieve(20000000);
 	map<int,int>d;
 	for (int i = 1; i <= n; i++) {

 		int x,a;
 		cin >> x;
 		x = i;

 		a = x;
 		// if (x == 1) continue;
 		// if (d[x] == 1) {
 		// 	res++;
 		// 	continue;
 		// }

 		// if (d[x] == 2) continue;

 		// if (trace[x] == x) continue;

	 	vector<int>fac;
	 	while (x > 1) {
	 		int u = trace[x];
	 		fac.pb(u);
	 		while(x % u == 0) {
	 			x /= u ;
	 			cnt[u]++;
	 		}
	 	}
	 	// for (auto i : fac) cout << i << ' '<<cnt[i] <<endl;
	    backtrack(0, fac, 1);
	    sort(All(s));

	    int check = 1;
	    for (auto i : s) {
	    	if (i == a || i == 1) continue;
	    	if (trace[i] != i) {
	    		check = 0;
	    		break;
	    	}
	    } 

	    cout << a << endl;
	    for (auto i : s) cout << i << ' ' ;
	    EL;
		EL;

	    if (check == 1) d[a] = 1;
	    else d[a] = 2;
	    res +=  check;
	    // if (check) cout << a << endl;
		for (auto i : fac) cnt[i] = 0;
		s.clear(); 
 	}

 	// cout << res;
    return 0;
}