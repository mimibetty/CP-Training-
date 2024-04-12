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

char a[12][12];

int p[12][12];
void solve() {
    int res = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'X') {
                res += p[i][j];
            }
        }
    }
    cout << res << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n = 10;
    for (int i = 1; i <= n; i++) {
        p[1][i] = p[n][i] = p[i][1] = p[i][n] = 1;
    }
    pii vt = {2,2};
    for (int i = 2; i <= n/2; i++) {
        vt = {i,i};
        p[vt.fi][vt.se] = i;
        while (p[vt.fi][vt.se + 1] == 0 && vt.fi >= 1 && vt.fi <= 10
         && vt.se + 1>= 1 && vt.se + 1 <= 10) {
            p[vt.fi][vt.se + 1] = i;
            vt.se++;
        }
        while (p[vt.fi + 1][vt.se] == 0 && vt.fi + 1 >= 1 && vt.fi + 1 <= 10
         && vt.se >= 1 && vt.se <= 10) {
            p[vt.fi + 1][vt.se] = i;
            vt.fi++;
        }


        while (p[vt.fi][vt.se - 1] == 0 && vt.fi  >= 1 && vt.fi  <= 10
         && vt.se - 1 >= 1 && vt.se - 1 <= 10) {
            p[vt.fi ][vt.se - 1] = i;
            vt.se--;
        }

        while (p[vt.fi -1][vt.se] == 0 && vt.fi -1  >= 1 && vt.fi -1  <= 10
         && vt.se >= 1 && vt.se <= 10) {
            p[vt.fi -1 ][vt.se] = i;
            vt.fi--;
        }
    }

    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j <= 10; j++) {
    //         cout << p[i][j];
    //     }
    //         cout << endl;
    // }
    int t;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}