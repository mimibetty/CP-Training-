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
 
vector<int>adj[200005];
int d[200005];
bool vs[200005];
long long dp[200005][5];

int n,m;
int s,t;

void bfs(int u) {
	queue<int>q;
	q.push(u);

	while(q.size()) {
		auto p = q.front();
		vs[p] = 1;
		q.pop();
		for(auto i : adj[p]) {
			if (vs[i]) continue;
			d[i] = d[p] + 1;
			vs[i] = 1;
			q.push(i);
		}
	}

}

long long cal(int u) {
	ll res = 0;
	if (u == s) return 1;  
	if (dp[u][1] != -1 && dp[u][0] != -1) {
		res = dp[u][1];
		res %= MOD;

		res += dp[u][0];
		res %= MOD;
		return res;
	}

	for (auto v : adj[u]) {	
		if (d[u] == d[v]) {
			dp[u][1] += dp[v][0];
			 dp[u][1] %= MOD;
		}
		if (d[u] == d[v] + 1) {
			dp[u][0] += dp[v][0];
			dp[u][0] %= MOD;

			dp[u][1] += dp[v][1];
			dp[u][1] %= MOD;
		}
	} 

}
void solve() {
	cin >> n >> m;
	cin >> s >> t;

	for (int i = 1; i <= n; i++) {
  		adj[i].clear();
  		d[i] = 0;
  		vs[i] = 0;
  		dp[i][1] = dp[i][0] = -1;	
  	}

	int u,v;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bfs(s);
  
  	
  	dp[s][0] = 1;

  	for (int i = 1; i <= n; i++) {
  		int u = edgs[i].se;
  		for (auto v : adj[u]) {	
  			if (d[u] == d[v]) {
  				dp[u][1] += dp[v][0];
  				 dp[u][1] %= MOD;
  			}
  			if (d[u] == d[v] + 1) {
  				dp[u][0] += dp[v][0];
  				dp[u][0] %= MOD;

  				dp[u][1] += dp[v][1];
  				dp[u][1] %= MOD;
  			}
  		} 
  	}
  	cout << cal(t) << endl;
  	// for (int i = 1; i <= n; i++) {
  	// 	cout << "EDGES:" <<  i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
  	// }
  	// ll res = dp[t][1] % MOD;
  	// res += dp[t][0];
  	// res %= MOD;
  	// cout << res << endl;


  	 
}


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int test;
 	cin >> test; 
 	while (test--) {
 		solve();
 	}
    return 0;
}