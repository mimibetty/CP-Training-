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
    
ll x[5];
void solve() {
    int n;
    cin >> n;
    string s[5][1005];
    map<string,int>d;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
            d[s[i][j]]++;
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[s[i][j]] == 1) x[i] += 3;
            if (d[s[i][j]] == 2) x[i] += 1;
        }
    }

    for (int i = 1; i <= 3; i++) {
        cout << x[i] << ' ';
        x[i] = 0;  
    } 
    cout << endl;
    d.clear();
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