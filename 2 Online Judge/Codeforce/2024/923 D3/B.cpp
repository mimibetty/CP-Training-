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

int a[200005];
vector<char>f[200005];
void solve() {
    int maxx = 0;
    int n;
    cin >> n;
    // if (n == 11) {
    //     cout << "abracadabra "  << endl;
    //     return;
    // }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(a[i], maxx);
        // cout << a[i] << endl;
    }

    for (char i = 'a' ; i <= 'z'; i++) {
        f[0].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        char x = f[a[i]].back();
        cout << x;
        f[a[i]].pop_back();
        f[a[i] + 1].pb(x);
    }
    cout << endl;
    for (int i = 0; i <= maxx; i++) {
        f[i].clear();
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
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}