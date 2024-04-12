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
 
const int maxN = 2e5 + 5;
vector<int>adj[maxN];
int cost[maxN];
int parent[maxN];

void dfs(int u, int p) {

	for (auto i : adj[u]) {
		if (i == p) continue;
		parent[i] = u;
		cost[i] = cost[u] + 1;
		dfs(i, u);
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int diameter = 0;
 	int root1 = 0, root2 = 0;
 	int n;
 	cin >> n;

 	for (int i = 1; i <= n-1; i++) {
 		int u,v;
 		cin >> u >> v;
 		adj[u].pb(v);
 		adj[v].pb(u);
 	}

 	cost[1] = 1;
 	dfs(1,0);

 	for (int i = 1; i <= n; i++) {
 		if (cost[i] > cost[root1]) root1 = i;
 	}
 	
 	cost[root1] = 1;
 	dfs(root1,0);
 	parent[root1] = 0;


 	for (int i = 1; i <= n; i++) {
 		if (cost[i] > cost[root2]) {
 			root2 = i;
 			diameter = cost[root2] - 1;
 		}
 	}  

 	cout << root1 << ' ' <<root2 <<endl;
    int p = root2;
    
    while(p != 0) {
    	cout << p << ' ';
    	p = parent[p];
    }
    
    return 0;
}