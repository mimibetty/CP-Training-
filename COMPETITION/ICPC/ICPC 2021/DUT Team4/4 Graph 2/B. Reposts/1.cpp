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
 
string s1[205],s2[205];

map<string,vector<string>>adj;
map<string,int>cost;
map<string,bool>vs;
int res = 0;

void bfs(string s, int &res) {
    queue <string> q;
    q.push(s);
    vs[s] = 1;
    while (q.size()) {
        string u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            if (vs[i] == 0) {
                vs[i] = 1;
                cost[i] = cost[u] + 1;
                res = max(res, cost[i]);
                q.push(i);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;

 	for (int i = 1; i <= n; i++) {
 		string s;
 		cin >> s1[i] >> s >> s2[i];
 		for (int j = 0; j < s1[i].size(); j++) {
 			if (s1[i][j] >= 'A' && s1[i][j] <= 'Z') s1[i][j] = s1[i][j] + 32;
 		}
 		for (int j = 0; j < s2[i].size(); j++) {
 			if (s2[i][j] >= 'A' && s2[i][j] <= 'Z') s2[i][j] = s2[i][j] + 32;
 		}
 		adj[s2[i]].pb(s1[i]);
 		// cout << s1[i]<< ' '  << s << ' ' << s2[i] <<endl;
 	}
 	bfs("polycarp", res);
 	cout << res+1 <<endl; 
    return 0;
}