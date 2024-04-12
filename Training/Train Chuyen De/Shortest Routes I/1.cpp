#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<long long,int> pli;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

vector<pli>adj[100005];
int n,m;
ll d[100005];

void dijkstra(int u) {
    for (int i = 1; i <= n; i++) d[i] = oo;

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[u] = 0;
    pq.push({0,u});

    while(pq.empty() == 0) {
        auto q = pq.top();
        pq.pop();

        if (d[q.se] != q.fi) continue;
        cout << q.fi << ' ' << q.se << endl; 
        for (auto i : adj[q.se]) {
            if (d[i.se] == oo || d[i.se] > d[q.se] + i.fi) {
                d[i.se] = d[q.se] + i.fi;
                pq.push({d[i.se], i.se});
            }
        }
    }

    return;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v,c;
        cin >> u >> v >> c;

        adj[u].pb({c,v});
        adj[v].pb({c,u});
    }    



    // priority_queue<pli, vector<pli>, greater<pli>> pq;
    // pq.push({1,2});
    // pq.push({2,3});
    // while(pq.empty() == 0) {
    //     cout << pq.top().fi << ' ' << pq.top().se <<endl;
    //     pq.pop();
    // }
    // return 0;
    dijkstra(1);
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}