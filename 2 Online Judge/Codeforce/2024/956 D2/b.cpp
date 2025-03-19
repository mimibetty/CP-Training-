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

char a[501][501];
char b[501][501];

int hieu[501][501];
int cap[5];
void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            hieu[i][j] = abs(b[i][j] - a[i][j]);
            // cout << hieu[i][j] << ' ';
            // res += hieu[i][j];
            // cap[hieu[i][j]]++;
        }

        // cout << endl;
    }


    // for (int i = 0; i <= 2; i++) cout << cap[i] << ' ';
    // cout << endl;
    // cout << "rerr   "<< res << endl; 
    // cout << endl << endl;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         hieu[i][j] = 0;
    //     }
    // }
    // for (int i = 0; i <= 2; i++) cap[i] = 0;

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