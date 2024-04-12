#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[705][705];
bool vs[705][705];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1}; 

bool isvalid(int x, int y) {
	if (x > 0 && x <= n && y > 0 && y <= m && vs[x][y] == 0 && a[x][y] > 0) return 1;
	else return 0;
}

void bfs (int x,int y) {
	queue<pair<int,int>>q;
	q.push({x,y});

	while ( !q.empty() ) {
		auto g = q.front();
		q.pop();
		
        for (int i = 0; i <= 7; i++) {
            int newU = g.first + dx[i];
            int newV = g.second + dy[i];
            if (isvalid(newU, newV) == 1) {
                vs[newU][newV] = 1;
                bfs(newU, newV);   
            }          
        }	
	}
}

struct Edge {
    int x;
    int y;
    int h;
};

bool cmp(const Edge &a, const Edge &b) {
    if (a.h > b.h) return (a.h > b.h);
    else return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    vector<Edge>edge ;
    int res = 0;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    	    edge.push_back({ i, j, a[i][j]});
        }
    }

    sort(edge.begin(), edge.end(),cmp);

    int cnt = 0;
    for (auto i : edge) {
        if (vs[i.x][i.y] == 0) {
            res++;
            vs[i.x][i.y] = 1; 
            bfs(i.x, i.y);
        }
    }
 	cout << res;

    return 0;
}



