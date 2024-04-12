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
 
int n,m,s;		 
vector<int>adj[100005];
int cost[100005];
bool vs[100005];

void bfs(int u) {
	queue<int>q;
	q.push(u);

	while(q.size()) {
		auto p = q.front();
		vs[p] = 1;
		q.pop();

		for (auto i : adj[p]) {
			if (vs[i]) continue;
			cost[i] = cost[p] + 1;
			vs[i] = 1;
			q.push(i);
		}
	}
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	cin >> n >> m >> s;

	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs(s);
	vector<pair<int,int>>res;

	for (int i = 1; i <= n; i++) {
		if (cost[i] == 0) {
			if (i == s) res.pb({0,i});
		}
		else {
			res.pb({cost[i],i});	
		}
	}
	sort(All(res));
	for (auto i : res) cout << i.se << ' '<< i.fi << endl;
    return 0;
}