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

int x[105];
int a[105][105];

void solve() {
    int n;
    cin >> n;
    map<int,int>d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        
        char z;
        cin >> z;
                
        map<int,int>ff;
        for (int j =1; j <= x[i]; j++) {
            cin >> a[i][j];
            ff[a[i][j]] = 1;
        }
        for (auto i : ff) {
            d[i.fi]++;
        }
    }   
    for (auto i : d) {
        // cout << i.fi << ' ' << i.se << endl;
        if (i.se == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" <<endl;
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
    while (t--)    
    solve();
    
    return 0;
}