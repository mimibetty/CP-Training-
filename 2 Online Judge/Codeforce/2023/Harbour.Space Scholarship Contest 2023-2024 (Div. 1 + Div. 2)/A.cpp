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
int a[1005];
void solve() {

    int x,y,n;
    cin >> x >> y >> n;
    a[1] = x;
    a[n] = y;
    int z = 1;
    for (int i = n- 1; i> 1 ;i--) {
        a[i] = a[i+1] - z;
        z++;
    }
    vector<int>r;
    for (int i = 2; i <= n; i++) {
        r.pb(a[i] - a[i-1]);
    }

    // for (int i = 1;  i<= n; i++) cout << a[i] << ' ';
    //     EL;
    for (int i = 0; i < r.size() - 1; i++) {
        if (r[i] <= r[i+1]) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1;  i<= n; i++) cout << a[i] << ' ';
        EL;
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
    while (t--)
    solve();
    
    return 0;
}