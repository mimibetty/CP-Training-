#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100005];
bool vs[100005];
int par[100005];
bool check;


void dfs(int n) { 
	vs[n] = 1;
	for (auto i :adj[n]) {
		if (vs[i] == 0) {
			par[i] = n;
			vs[i] = 1;
			dfs(i);
		}
		else if (vs[i] == 1 && par[n] != i) {			
			 
			vector<int> trace;
			check = 1;

			int k = i;
			int x = n;
			trace.push_back(i);
			while ( x != k) {
				trace.push_back(x);
				x = par[x]; 
			}
			trace.push_back(i);
			reverse(trace.begin(), trace.end());

			cout << trace.size() << endl;
			for (auto s :trace) cout << s <<' ';
			exit(0);
			}
		}
	}

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	 	
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
    	int u,v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    check = 0;
    for (int i = 1; i <= n; i++) {    	
    	//cout << i << endl;
    	if (vs[i] == 1) continue;
    	if (check == 0 && vs[i] == 0) dfs(i);
    	if (check == 1)  {
    		break;	
    	}
    }
    if (check == 0) cout << "IMPOSSIBLE";
    return 0;
}