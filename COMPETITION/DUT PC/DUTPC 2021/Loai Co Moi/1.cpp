#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define cnt_bit __builtin_popcount

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

//int a[1000005];
int v[10];
char a[1005][1005];
int n,m,sl;

int cost[1005][1005];
bool vs[1005][1005];
pair<int,int> par[1005][1005];
deque<pair<int,int>>team[10];
vector<pair<int,int>>teamNew;

bool is_valid(int x,int y) {
    if (x > 0 && x <= n && y > 0 && y <= m && a[x][y] != '#') return 1;
    else return 0;
}


void bfs( deque<pair<int,int>>sources, int num) {
    for (auto i : sources) {
        team[num].push_back({i.first,i.second});
        cost[i.first][i.second] = 0;
    }

    while (!team[num].empty()) {
        auto u = team[num].front();
        vs[u.first][u.second] = 1;
        team[num].pop_front();
        for (int i = 0; i <= 3; i++) {
            int newX = u.first + d4x[i];
            int newY = u.second + d4y[i];   
            if (is_valid(newX,newY) == 1 && vs[newX][newY] == 0 && a[newX][newY] == '.' && cost[u.first][u.second] < v[num]) {
                    a[newX][newY] = num + '0'; 
                    cost[newX][newY] = cost[u.first][u.second] + 1;                
                    if (cost[newX][newY] == v[num]) teamNew.push_back({newX,newY});                
                    else {
                        team[num].push_back({newX,newY});
                        vs[newX][newY] = 1;
                    }
                    par[newX][newY] = {u.first,u.second};
            }         
        }
    }
}

int res[1005];

int main() {
    freopen("input.txt", "r", stdin);       
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    
    cin >> n >> m >> sl;
    
    for (int i = 1; i <= sl; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] != '.' && a[i][j] != '#') {
                int num = a[i][j] - '0';
                team[num].push_back({i,j});
            }
        }
    }

    bool done = 0;
    while (done == 0) {
        for (int i = 1; i <= sl; i++) {
                bfs(team[i], i);
                for (auto j : teamNew) {
                    int vt1 = j.first, vt2 = j.second;
                    team[i].push_back({vt1,vt2});
                }
                teamNew.clear();
                int dem = 0;
                for (int r = 1; r <= 9; r++) {
                    if (team[r].empty() == 1) dem++;
                }
                if (dem == 9) done = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] >= '1' && a[i][j] <= '9') res[a[i][j]]++;
        }
    }

    for (char i = '1'; i <= (char)(sl + '0'); i++) cout << res[i] << ' ';
    
    return 0;
}
