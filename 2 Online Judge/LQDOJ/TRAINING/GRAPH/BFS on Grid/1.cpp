#include<bits/stdc++.h>
using namespace std;
 
int n, m;
char a[1005][1005];
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
bool vs[1005][1005];
int d[1005][1005];
pair<int, int> par[1005][1005];
 
bool isValid(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '*') return 1;
    else return 0;
}
 
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vs[x][y] = 1;
 
    while (!q.empty()) {
        auto i = q.front();
        q.pop();
        // cout << i.first << ' ' << i.second << endl;
 
        for (int j = 0; j <= 3; j++) {
            int u = i.first + dx[j];
            int v = i.second + dy[j];
 
            if (vs[u][v] == 0 && isValid(u, v)) {
                vs[u][v] = 1;
                d[u][v] = d[i.first][i.second] + 1;
                par[u][v] = {i.first, i.second};
                q.push({u, v});
            }
        }
    }
}
 

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    int x1,x2,y1,y2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'G') {
                x1 = i;
                y1 = j;
            }
            if (a[i][j] == 'R') {
                x2 = i;
                y2 = j;
            }
        }
    }
     bfs(x1,y1);
    cout << d[x2][y2];

    return 0;
}