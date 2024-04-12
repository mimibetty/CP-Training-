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
 

vector <int> adj[2005];
int cost[2005];
bool vs[2005];

void bfs(int n) {
    queue <int> q;
    q.push(n);
    vs[n] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            if (vs[i] == false) {
                vs[i] = true;
                cost[i] = cost[u] + 1;
                q.push(i);
            }
        }
    }
}

int a[2005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == -1) a[i] = 0;
        adj[a[i]].push_back(i);
        adj[i].push_back(a[i]);
 	}
 	bfs(0);
 	int res = 0;
 	for (int i = 1; i <= n; i++) {
 		res = max(res, cost[a[i]]);
 	}
 	cout << res + 1;
    return 0;
}