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
 
vector<int>adj[100005];
map<pii,int>d;
bool check = 1;

void dfs(int u, int p, int wei) {
	
	if (adj[u].size() > 2) {
		check = 0;
		return;
	}

	if (u == 1) {
		int cnt = 0;
		for (auto i : adj[u]) {
			if (i == p) continue;
			cnt++;
			if (cnt == 1) {
				d[{u, i}] = 2;
				d[{i, u}] = 2;
				dfs(i,u,2);
			}
			if (cnt == 2) {
				d[{u, i}] = 3;
				d[{i, u}] = 3;
				dfs(i,u,3);
			}
		}
	}
	else {
		for (auto i : adj[u]) {
			if (i == p) continue;
			int h = 5 - wei;
			d[{i,u}] = h;
			d[{u,i}] = h;
			dfs(i, u, h);
		}	
	}

}

void solve() {
	int n;
	cin >> n;	
	vector<pii>pos;

	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);

		pos.pb({u,v});
	}

	dfs(1,0,2);
	if (check == 0) {
		cout << -1 << endl;
		d.clear();
		check = 1;
		for (int i = 1; i <= n; i++) adj[i].clear();
		return;
	}
	else {
		for (auto i : pos) {
			cout << d[{i.fi,i.se}] << ' ';
		}
		cout <<endl;
		check = 1;
		for (int i = 1; i <= n; i++) adj[i].clear();
		d.clear();
		return;
	}

}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);	
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}

    return 0;
}