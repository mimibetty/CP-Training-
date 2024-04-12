#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

char a[55][55];
bool vs[55][55];
int cd[55][55];
int n,m;
bool valid(int x,int y) {
    if (x >= 1 && x <= n && y >= 1  && y <= m) return 1;
    return 0;
}
int temp = 0;
void dfs(int x,int y) {
    vs[x][y] = 1;
    int cnt = 0;
    for (int z = 0; z < 4; z++) {
        int xx = dx[z] + x;
        int yy = dy[z] + y;
        if (valid(xx,yy)) {
            if (a[xx][yy] == '*') cnt++;
        }
    }
    if (cnt == 4) {
        temp = -1;
        return;
    }
    if (cnt == 3) temp++;

    for (int z = 0; z < 4; z++) {
        int xx = dx[z] + x;
        int yy = dy[z] + y;
        if (valid(xx,yy)) {
            if (a[xx][yy] == '*' && vs[xx][yy] == 0) {
                dfs(xx,yy);
            }
        }
    }
    
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ok1 = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') continue;
            int cnt = 0;
            for (int z = 0; z < 4; z++) {
                int xx = dx[z] + i;
                int yy = dy[z] + j;
                if (valid(xx,yy)) {
                    if (a[xx][yy] == '*') cnt++;
                }
            }
            if (cnt == 4 || cnt == 3) {
                cout << "no" <<endl;
                return;
            }
            if (cnt == 2) ok1 = 1;
        }
    }


    // check >= 2 L 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i][j] == '*' && vs[i][j] == 0) {
                dfs(i,j);
                if (temp == -1 || temp > 1) {
                    temp = 0;
                    cout << "no" << endl;
                    return;
                }
            }
        }
    }
    if (ok1) cout << "yes" << endl;
    else {
        cout << "no" << endl;
    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

3 
1 2 
4 5 
7 8
10 11 
13 14 
16 17 
19 20
22 23 
25 26
28 29 
31 32 
