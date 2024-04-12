#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define pb push_back
#define mp make_pair
#define X first
#define Y second
 
const ll LINF = 1E18;
const int INF = 1E9;
 
const int N = 10005;
 
ll n, m, S, F, d[N], Free[N], trace[N];
vector <ii> path[N];
 
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        path[u].pb(ii(v, w));
        path[v].pb(ii(u, w));
    }
    
    cin >> S >> F;
}
 
void Dijkstra(int S){
    priority_queue <ii, vector <ii>, greater <ii>> PQ;
    PQ.push(ii(0, S));
    for(int i = 1; i <= n; i++) d[i] = INF;
    d[S] = 0;
    trace[S] = S;
 
    while(PQ.size()) {
        int u = PQ.top().second;
        int du = PQ.top().first;
        PQ.pop();
        if(Free[u]) continue;
        Free[u] = 1;
        //cout << u << ' ' << du << endl;
 
        for(int i = 0; i < path[u].size(); i++) {
            //cout << i << endl;
            int v = path[u][i].first;
            int dv = path[u][i].second;
 
            if(d[v] > d[u] + dv) {
                d[v] = d[u] + dv;
                PQ.push(ii(d[v], v));
                trace[v] = u;
            }
        }
    }
}
 
void Solve(){
    Dijkstra(S);
    //for(int i = 1; i <= n; i++) cout << d[i] << ' ';
    if (d[F]==INF){
        cout<<"NO WAY HOME"; return;
    }
    cout<<"Distance : "<<d[F]<<" km\nWay : ";
    vector <int> answer;
    int u=F;
    while(u!=trace[u]){
        answer.pb(u);
        u=trace[u];
    }
    answer.pb(S);
    for (int i=answer.size()-1;i>=0;i--) cout<<answer[i]<<" ";
}
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("icecream.txt","r",stdin);
    int t = 1;
    //cin >> t;
    while (t--){
        Input();
        Solve();
    }
    return 0;
}
/*
4 4 
1 2
1 2 100
1 3 1
3 4 1 
4 2 1
 
6 6
1 6
1 2 1
2 3 1
3 6 1
1 4 100
4 5 100
5 6 100
*/