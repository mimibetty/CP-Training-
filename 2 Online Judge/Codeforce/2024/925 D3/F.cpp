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

void solve() {
    int n,m;
    cin >> n >> m;
    map<pii, int>truoc;
    map<pii, int>sau;
      vector<vector<int>> a(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n ;j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n ;j++) {
            if (j > 2) {
                truoc[{a[i][j-1], a[i][j]}]++;
            }
            if (j + 1 <= n && j > 1) {
                sau[{a[i][j], a[i][j + 1]}]++;
            }
        }
    }
    cout << "TRUOC  " << endl;
    for (auto i : truoc) {
        pii x = i.fi ;
        int y = i.se;
        cout << x.fi << ' ' << x.se << ' ' << y << endl;
    }

    cout << "sau  " << endl;
    for (auto i : sau) {
        pii x = i.fi ;
        int y = i.se;
        cout << x.fi << ' ' << x.se << ' ' << y << endl;
    }
    cout << "GHUGUG" << endl;
    cout << endl << endl;
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