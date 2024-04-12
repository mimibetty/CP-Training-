#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 1e18;
 
long long dist[505][505];
long long Trace[505][505];

vector<int> trace(int u, int v) {
    vector<int> path;
    do {
        path.push_back(u);
        u = Trace[u][v];
    } while (path.back() != v);
    return path;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int vertice , edge, query;
    cin >> vertice >> edge >> query;
    
    // khoi tao dist, cac cap (u,v) (u != v) dist(u,v) = +oo;
    for (int i = 1; i <= vertice ; i++) {
        for (int j = 1; j <= vertice ; j++) {
            if (i != j) dist[i][j] = INF;
            else Trace[i][j] = i;
        }
    }
    
    // khoi tao dist(u,v) nhu de cho
    for (int i = 1; i <= edge; i++) {
        int u, v, c;
        cin >> u >> v >> c;
 
        dist[u][v] = min((long long) c, dist[u][v]);
        dist[v][u] = min((long long) c, dist[v][u]);
        Trace[u][v] = v;
        Trace[v][u] = u;
    }
    
    // tim duong di ngan nhat tu u > v
    for (int k = 1; k <= vertice ; k++) {
        for (int i = 1; i <= vertice ; i++) {
            for (int j = 1; j <= vertice ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    Trace[i][j] = Trace[i][k];  
                }
            }
        }
    }
    
    for (int z = 1; z <= query; z++) {
        int x, y;
        cin >> x >> y;
        cout << "Test " << z << " : ";
        if (dist[x][y] == INF) dist[x][y] = -1;   // khong the den duoc 
        if (x > vertice || x <= 0 || y > vertice || y < 0) {
            cout << "Invalid" << endl << endl;
            continue;
        }
        
        if (dist[x][y] == -1) {
            cout << "Invalid" << endl << endl;
            continue;
        }

        cout << dist[x][y] << endl;
        
        cout << "Path : ";
        vector<int>path = trace(x,y);
        for (auto i : path) cout << i << ' ' ;
        cout << endl << endl;

    }
    return 0;
}