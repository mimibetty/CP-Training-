/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

int a[102][102];

int n,m;
bool valid(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    return 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
            bool ok = 1;
            int maxx = 0;
            for (int k = 0; k < 4; k++) {
                int xx = dx[k] + i;
                int yy = dy[k] + j;
                if (valid(xx,yy)) {
                    maxx = max(maxx, a[xx][yy]);
                    if (a[i][j] < a[xx][yy]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                a[i][j] = maxx;
            }

        }
    }

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            cout  << a[i][j] << ' ';
        }
        cout << endl;
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

    while (t--)    
    solve();
    
    return 0;
}