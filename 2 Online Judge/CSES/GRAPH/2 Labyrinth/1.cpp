#include <bits/stdc++.h>
using namespace std;
 
int n,m;
char a[1005][1005];
int d[1005][1005];
pair <int,int> par[1005][1005];
bool vs[1005][1005];
 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
 
bool IsValid(int x, int y) {
    if ( x <= n && x > 0 && y <= m && y > 0 && a[x][y] != '#' ) return 1;
    else return 0;
}
 
void bfs(int x, int y) { 
    queue<pair<int,int>> q;
    q.push({x,y});
    vs[x][y] == 1;
 
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int u ;
        int v ;
        
        for (int i = 0; i < 4; i++) {
            u = p.first + dx[i];
            v = p.second + dy[i];
            if (IsValid(u,v) == 1 && vs[u][v] == 0) {
                q.push({u,v});
                d[u][v] = d[p.first][p.second] + 1;
                par[u][v] = {p.first,p.second};  
                vs[u][v] = 1;
            }  
        }    
    }
    
 
}
 
int main() {
  //  freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<char>trace;
    cin >> n >> m;
 
    int xa,xb,ya,yb;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') { 
                xa = i;
                ya = j; 
            }
            else if (a[i][j] == 'B') {
                xb = i;
                yb = j;
            }
        }
    }
 
    bfs(xa,ya);
 
    if (vs[xb][yb] == 0) cout << "NO";
    else {
        cout << "YES" << "\n";
        cout << d[xb][yb] << "\n";
 
        int x = xb, y = yb;
        while (x != xa || y != ya) {
        //  cout << x << ' ' << y << endl;
            int xx = x, yy = y;
            auto p = par[x][y];
            x = p.first;
            y = p.second;
            if (xx == x - 1) trace.push_back('U');
            if (xx == x + 1) trace.push_back('D');
            if (yy == y - 1) trace.push_back('L');
            if (yy == y + 1) trace.push_back('R');
        }
            if (xa == x - 1) trace.push_back('U');
            if (xa == x + 1) trace.push_back('D');
            if (ya == y - 1) trace.push_back('L');
            if (ya == y + 1) trace.push_back('R');
        //  cout << xa << ' ' << ya << endl;
            reverse(trace.begin(), trace.end() );
    }
 
    for (auto i : trace) cout << i;
    return 0;
}