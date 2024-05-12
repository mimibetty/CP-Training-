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

long long a[200005];
long long f(int l, int r) {
    ll f = 0;
    for (int i = l; i <= r; i++) {
        f ^= a[i];
    } 
    return f;
}
void solve() {
    int n,t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int z = 1; z <= t; z++) {
        int l,r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            cout << "{ " << l << ' ' << j << ",  " << 
            j + 1 << ' ' << r << "} " << f(l,j) << ' ' << f(j + 1, r) 
            << "?? " <<(f(l,r)^f(l,r) )<< " " << (f(l,r)^f(j+1,r))<< endl;
        }
        cout << f(l,r) << endl;
    }
    cout << endl;
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

set<pair<int,int>> s;
s.erase(4);
s.erase(s.find(4));