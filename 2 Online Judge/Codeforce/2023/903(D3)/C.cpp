/*
link submit: 
Note:
*/
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

int n;
char a[1005][1005];
bool vs[1005][1005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            vs[i][j] = 0;
        }
    }    
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vs[i][j] == 0) {
                vector<pii>p;
                p.pb({i,j});
                pii x1 = {i,j};
                for (int f = 1; f <= 3; f++) {
                    x1 = {x1.se, n - x1.fi + 1};
                    p.pb(x1);
                }
                int maxx = 0;
                for (auto z : p) {
                    vs[z.fi][z.se] = 1;
                    maxx = max(maxx, int(a[z.fi][z.se]));
                }
                for (auto z : p) {
                   res +=maxx - int(a[z.fi][z.se]);
                }
            }
        }
    }    
    cout <<res <<endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}