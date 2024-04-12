#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define fi first 
#define se second
#define pb push_back
#define EL cout << endl;


string s[405];
long long extra[405];
map<string,int>dic;
map<string,int>phuongtien;

// for every edge u, v with length c:
// adj[u].push_back(II(v, c));
// adj[v].push_back(II(u, c)); if 2-way edge

// use struct when there are more than 3 nums

struct Data{
    ll cost;
    int place;
    int transport;

    // bool operator() (Data a, Data b) {
    //     return a.cost < b.cost;
    // }

};
struct CMP {
    bool operator() (Data a, Data b) {
        return a.cost > b.cost;
    }
};
    
struct Dijkstra {
    vector<vector<Data>> adj;
    vector<ll> d; // shortest dist
    int n; // number of vertices

    Dijkstra(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, int c, int way) {
        adj[u].push_back({c, v,way});
        adj[v].push_back({c, u, way});
    }
    
    void dijkstra(int a) {
        priority_queue <Data, vector<Data>, CMP> pq;

        for (int i = 1; i <= n; i++) {
            d[i] = 1e18;
        }

        d[a] = 0;

        pq.push({0, a, 0});
        while (pq.size()) {
            ll du = pq.top().cost;
            int u = pq.top().place;
            int x = pq.top().transport;
            
            pq.pop();
            
            if (d[u] != du) continue;
            
            for (auto i: adj[u]){
                int v = i.place;
                ll uv = i.cost;
                int trans = i.transport;

                ll sum = uv + du;
                if (x != trans && x != 0) sum +=  extra[u];
                // this v is better
                
                if (d[v] > sum){
                    // cout << v << ' ' << d[v] << ' ' << trans << ' ' << u << ' ' << du << ' ' << x << endl;
                    d[v] = sum;
                    pq.push({sum,v,trans}); // push the better one
                    // cout << d[v] << endl;
                }
            }
        }
    }
};

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> extra[i];
        dic[s[i]] = i;
    }

    Dijkstra ff(n);
    int q;
    cin >> q;
    
    string s1,s2;
    for (int z = 1; z <= q; z++) {
        string way;
        long long Cost;
        cin >> s1 >> s2 >> way >> Cost;
        ff.addEdge(dic[s1], dic[s2], Cost, phuongtien[way]);
        // cout  << s1 << s2 << way << Cost << endl;
    }
        cin >> s1 >> s2;
        int place1 = dic[s1], place2 = dic[s2];
        ff.dijkstra(place1);

        cout << ff.d[place2] << endl;

}
    
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    phuongtien["AIR"] = 1;
    phuongtien["TRUCK"] = 2;
    phuongtien["RAIL"] = 3;
    phuongtien["SEA"] = 4;
    
    // priority_queue<Data, vector<Data>, CMP> pq;
    //         pq.push({3,5,2});
    //         pq.push({4,5,2});
    //         pq.push({9,5,2});
    //         pq.push({3,3,2});
    // while(pq.size()) {
    //     cout << pq.top().cost << ' '<< pq.top().place << endl;
    //     pq.pop();
    // }

    int t;
    cin >> t;

    while (t--) {
        solve();        
    }
    return 0;
}