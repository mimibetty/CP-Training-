#include <bits/stdc++.h>
using namespace std;

int n,m;

char a[1005][1005];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};


int cost[1005][1005];
bool vs[1005][1005];
pair<int,int> par[1005][1005];
bool is_valid(int x,int y) {
    if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] != '#') return 1;
    else return 0;
}


void bfs(int x, int y) {

    queue<pair<int,int>> q;
    q.push({x,y});
    vs[x][y] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            int newX = u.first + dx[i];
            int newY = u.second + dy[i];
            if (is_valid(newX,newY) == 1 && vs[newX][newY] == 0) {
                cost[newX][newY] = cost[u.first][u.second] + 1;                
                vs[newX][newY] = 1;
                q.push({newX,newY});
                par[newX][newY] = {u.first,u.second};
           //     bfs(newX,newY);
            }
        }
    }
}

int main() {
  //  freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<char>trace;
    int xa,ya,xb,yb;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                xa = i;
                ya = j;
            }
            if (a[i][j] == 'B') {
                xb = i;
                yb = j;
            }
        }
    }

    bfs(xa,ya);

    // TRACE 
    if (cost[xb][yb] == 0) cout << "NO";
    else {
        cout << "YES" << endl << cost[xb][yb] << endl;
       
        int x = xb, y = yb;
            while (x != xa || y != ya) {
            //  cout << x << ' ' << y << endl;
                auto p = par[x][y];
           //     cout << p.first << ' ' << p.second <<endl;
                if (p.first == x - 1) trace.push_back('D');
                if (p.first == x + 1) trace.push_back('U');
                if (p.second == y - 1) trace.push_back('R');
                if (p.second == y + 1) trace.push_back('L');
                x = p.first;
                y = p.second;
            }

            if (xa == x - 1) trace.push_back('U');
            if (xa == x + 1) trace.push_back('D');
            if (ya == y - 1) trace.push_back('L');
            if (ya == y + 1) trace.push_back('R');
        //  cout << xa << ' ' << ya << endl;
            reverse(trace.begin(), trace.end() );
            for (auto i : trace) cout << i;
    }    
    return 0;
}
