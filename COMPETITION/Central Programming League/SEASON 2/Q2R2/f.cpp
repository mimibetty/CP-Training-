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

struct Data
{
    int x,y;
};

long long dis(Data &a, Data &b) {
    long long f = 0;
    f = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    return f;  
}

long long dp[105][105][105]; // dp[vi tri hien tai] [so luong da di qua]
Data a[2005];
long long dist[2005][2005];

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int m,n;
    cin >> m >> n;
    int s = n + m;
    for (int i = 1; i <= m + n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    swap(a[m], a[s]);

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = 1e18;
        }
    }

    for (int u = 1; u <= s; u++) {
        for (int v = 1; v <= s; v++) {
            dist[u][v] = min(dis(a[u],a[v]), dist[u][v]);
            dist[v][u] = min(dis(a[u],a[v]), dist[v][u]);

        }
    }

    for (int k = 2; k <= n; k++) {
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return 0;
}