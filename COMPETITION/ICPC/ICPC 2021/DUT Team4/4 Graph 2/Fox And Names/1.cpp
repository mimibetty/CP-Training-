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
 
// if u can go to v, index of u < index of v

// can use to find the longest path btw any pair of vertices
string s[105];

struct TopoSort {
    int n;
    bool cycle = 0;
    vector<vector<int>> adj;
    vector<bool> visit;
    vector<int> res;
    vector<bool> inStack;

    TopoSort(int n): n(n) {
        adj.resize(n + 1);
        visit.resize(n + 1);
        inStack.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int n) {
        if (visit[n]) return;
        visit[n] = 1;
        inStack[n] = 1;
        for (auto i: adj[n]) {
            if (!visit[i]) dfs(i);
            else if (inStack[i]) cycle = 1;
        }
        inStack[n] = 0;
        res.push_back(n);
    }

    void topological_sort() {
        res.clear();
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                dfs(i);
            }
        }
        reverse(res.begin(), res.end());
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n ;
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 		cin >> s[i];
 	}

    TopoSort topo(26);

 	for (int i = 1; i < n; i++) {
 		int num = min(s[i].size(), s[i+1].size());
 		for (int j = 0 ; j < num; j++) {
 			if (j == num-1) {
 				if (s[i][j] == s[i+1][j]) {
 					if (s[i].size() > s[i+1].size() ) {
 						cout << "Impossible" <<endl;
 						return 0;
 					} 
 				}
 				else {
 					topo.addEdge(s[i][j] - 'a' + 1, s[i+1][j]- 'a' + 1);
 				}
 			}
            else {
                if (s[i][j] != s[i+1][j]) {
                    topo.addEdge(s[i][j] - 'a' + 1, s[i+1][j]- 'a' + 1);
                    break;
                }
            }
 		}
 	}

    topo.topological_sort();

    if (topo.cycle == 1) {
        cout << "Impossible" <<endl;
        return 0;
    }
    else {
        for (auto i : topo.res) {
            cout << (char)(i + 'a' - 1);
        }
    }
    return 0;
}