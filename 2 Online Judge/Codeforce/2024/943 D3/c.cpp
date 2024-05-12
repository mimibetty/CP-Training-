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

long long a[505];
long long x[505];

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    x[1] = 1e5;
    for (int i = 2; i <= n; i++) {
        x[i] = x[i-1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << ' '; 
    }
    // cout << endl;
    // for (int i = 2; i <= n; i++) {
    //     cout << x[i] % x[i-1] << ' ';
    // }
    // cout << endl;
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