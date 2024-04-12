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
 
int f,start, goal, up,down;
bool vs[1000005];
int cost[1000005];

bool check(int x) {
	if (x > 0 && x <= f) return 1;
	return 0;
}
void bfs(int u) {
	queue<int>q;
	q.push(u);
	vs[u] = 1;

	while (q.size()) {
		auto p = q.front();
		q.pop();

		if(check(p + up) == 1) {
			if (vs[p + up] == 0) {
				cost[p + up] = 1 + cost[p];
				vs[p + up] = 1;
				q.push(p + up);
			}
		}

		if(check(p - down) == 1) {
			if (vs[p - down] == 0) {
				cost[p - down] = 1 + cost[p];
				vs[p - down] = 1;
				q.push(p - down);
			}
		}
	}
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	cin >> f >>start >> goal >> up >>down;
 	bfs(start);

 	if (start == goal) {
 		cout << 0;
 		return 0;
 	}

 	if (cost[goal] == 0) {
 		cout << "use the stairs";
 	}
 	else cout << cost[goal];
    return 0;
}