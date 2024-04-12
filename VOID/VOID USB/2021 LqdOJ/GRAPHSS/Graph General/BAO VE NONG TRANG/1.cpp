#include<bits/stdc++.h>
using namespace std;

int n,m;

int dx[8] = {-1 ,-1 ,-1 ,0 ,0 ,1 ,1 ,1};
int dy[8] = {-1 ,0 ,1 ,1 ,-1 ,1 ,0 ,-1};

int a[705][705];
bool vs[705][705];
struct Data{
    int x,y,h;
};

bool is_valid(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= m) return 1;
    else return 0;
}

void dfs(int u, int v) {
    if (vs[u][v] == 0 && a[u][v] > 0) {
        vs[u][v] = 1;
        //cout << u << ' ' << v << endl;
        for (int i = 0; i <= 7; i++) {
            int newU = u + dx[i];
            int newV = v + dy[i];
            if (is_valid(newU, newV) == 1 && a[newU][newV] > 0 && a[u][v] >= a[newU][newV]) dfs(newU, newV);          
        }
    }
}

bool cmp(Data a, Data b) {
    return a.h > b.h;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int res = 0;
    vector<Data>data;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            data.push_back({i , j ,a[i][j]});
        }
    }

    sort(data.begin(),data.end(),cmp);
    for (auto i : data) {
        if (vs[i.x][i.y] == 0 && a[i.x][i.y] > 0) {
            res++;
            dfs(i.x, i.y);
                      //  cout << i.x <<' ' << i.y << ' '<< i.h << ' ' <<res << endl;

        }
    }
    cout << res  ;
    /*for (auto i : data) {
        cout << i.h<< ' ' << i.x << ' ' << i.y<< endl;
    }*/
    return 0;
}