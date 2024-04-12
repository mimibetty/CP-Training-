#include <bits/stdc++.h>
using namespace std;

int n;
char c[150][150];
int a[10005];
bool vs[105][105];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool isValid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n);
} 

void dfs(int x, int y) {
    vs[x][y] = 1;
    for (int d = 0; d < 2; d++) {
        int u = x + dx[d];
        int v = y + dy[d];
        if (isValid(u, v) && c[u][v] == '.') {
            dfs(u, v);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }

    long long res = 0;
    do {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                c[i][j] = '.';
                vs[i][j] = 0;
            }
        }

        if (a[1] == 1) continue;
        for (int i = 1; i <= n; i++) {
            c[i][a[i]] = '*';
        }

        dfs(1, 1);
        if (vs[n][n] == 0) {
            res++;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << c[i][j] << ' ';
                }
                cout << endl;
            }  
            cout << endl << endl;
        } 
    } while (next_permutation(a + 1, a + n + 1));
    
    cout << res;
    return 0;
}