#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int n,m;
int x,y,u,v;
int a[1005][1005];
int d[1005][1005];

struct inf {
    int cost,x,y;
};

// bool cmp(inf a, inf b) {
//  return a.cost < b.cost;
// }

struct cmp{

    bool operator() (inf a,inf b) {

        return a.cost > b.cost;

    }

};

bool isvalid(int x,int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    return 0;
}

void diskstra(int gx, int gy) {
    priority_queue<inf, vector<inf>, cmp > pq;  // tăng dần
    d[gx][gy] = 0;
    pq.push({0,gx,gy});

    while (pq.empty() == 0) {
        auto p = pq.top();
        pq.pop();
        if (p.cost != d[p.x][p.y]) continue;
        // cout <<p.cost << ' ' <<  p.x << ' ' << p.y << endl;
        
        // if (vs[x][y] == 1) continue;
        // vs[x][y] = 1;


        for (int i = 0 ; i < 4; i++) {
            int xx = dx[i] + p.x;
            int yy = dy[i] + p.y;

            if (isvalid(xx,yy) == 0) continue;

            if (d[xx][yy] == -1 || d[xx][yy] > p.cost + a[xx][yy]) {
                 d[xx][yy] = p.cost + a[xx][yy];
                 pq.push({d[xx][yy], xx, yy});
            }
        }
    }

    return;
}

int main() {

    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = -1;

            char aa;
            cin >> aa;
            // cout << aa << ' ';
            if (aa == 'G') {
                x = i; y = j;
            }
            if (aa == 'R') {
                u = i; v = j;
            }

            a[i][j] = aa - '0';
            if (aa < '0' || aa > '9') a[i][j] = 0; 
        }
    }
    diskstra(x,y);
    cout << d[u][v] <<endl;

        // priority_queue<inf, vector<inf>, cmp> pq;  //up
        // pq.push({1,2,3});
        // pq.push({2,2,3});
        // pq.push({1,3,3});
        // pq.push({2,2,6});
        // while (pq.empty() == 0) {
        //     auto p = pq.top();
        //     cout << p.cost << ' ' << p.x << ' '<< p.y << endl;
        //     pq.pop();
        // }


           //  priority_queue<int, vector<int>, greater<int> > pq;  // 
        // priority_queue<int> pq; 
        // for (int i = 1; i <= 4; i++) pq.push(i);

    return 0;
}