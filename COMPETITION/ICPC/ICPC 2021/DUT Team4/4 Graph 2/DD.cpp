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

string s[105]; 
vector <int> adj[1005];
int cost[1005];
bool vs[1005];
int check[200];

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

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	set<char>dd;
	// int ok = 1;
	for (int i = 1; i < n; i++) {
 		int num = min(s[i].size(), s[i+1].size());

 		for (int j = 0; j < num; j++) {
 			if (j == num - 1) {
 				if (s[i][j] == s[i+1][j]) {
 					if (s[i].size() > s[i+1].size()) {
 						cout << "Impossible" << endl;
 						return;
 					}
 				}
 				else {
 					// if (ok) {
 					// 	ch = s[i][j];
 					// 	ok = 0;
 					// }
 					dd.insert(s[i][j]);
 					dd.insert(s[i+1][j]);
 					check[s[i+1][j]] = 1;
 					adj[s[i][j]].pb(s[i+1][j]);
 				}
 			}
 			else {
 				if (s[i][j] != s[i+1][j]) {	
 					// if (ok) {
 					// 	ch = s[i][j];
 					// 	ok = 0;
 					// }
 					dd.insert(s[i][j]);
 					dd.insert(s[i+1][j]);
 					check[s[i+1][j]] = 1;
 					adj[s[i][j]].pb(s[i+1][j]);
 					break;
	 			}
 			}
 		}  
 	}
    // bfs(ch);
    // for (int i = 97; i <= 122; i++) cout << (char) i << ' '<<check[i];
    for (auto i : dd) {
    	if (check[i] == 0) {
    		// cout << i << endl;
    		bfs(i);
    	}
		// cout << i << ' ' << check[i] << endl;
    } 

    for (auto i : dd) {
    	if(!vs[i]) {
    		cout << "Impossible" <<endl;
    		return;
    	}
    }
    for (int i = 1; i < n; i++) {
 		int num = min(s[i].size(), s[i+1].size());

 		for (int j = 0; j < num; j++) {
 			if (j == num - 1) {
 				if (s[i][j] != s[i+1][j]) {
 					if (cost[s[i][j]] > cost[s[i+1][j]]) {
 						cout <<"Impossible" << endl;
 						return;
 					}
 				}
 			}
 			else {
 				if (s[i][j] != s[i+1][j]) {	
	 				if (cost[s[i][j]] > cost[s[i+1][j]]) {
 						cout <<"Impossible" << endl;
 						return;
 					}	
	 				break;
	 			}
 			}
 		}  
 	}
 	vector<pair<int,char>>a;
 	string res;
 	for (int i = 97; i <= 122; i++) {
 		if (!vs[i]) res += (char)i;
 		else {
 			a.pb({cost[i], char(i)});
 		} 
 	}
 	sort(All(a));
 	// for (auto i : a) cout << i.fi << ' ' << i.se << endl;
 	for (auto i : a) res += i.se;
 		cout << res;
 	// cout << ch << endl;

}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	solve();
    return 0;
}