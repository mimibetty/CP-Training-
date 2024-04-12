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

int a[55];
void solve() {
    ll n,s,r;
    cin >> n >> s >> r;
    a[1] = s - r;
    int f = a[1] * n;
    for (int i = 1; i <= n; i++) {
        a[i] = a[1];
    }    
    for (int i = 2; i <= n; i++) {
        while (a[i] > 1 && f > s) {
            a[i]--;
            f--;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    // double res1 = 0;
    // double res2 = 0;
    // double x,y;

    // while(cin >> x >> y) {
    //     res1 += x*y;
    //     res2 += y;
    // } 
    // cout << res1 << endl << res2 << endl;
    // cout << res1/res2;
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    return 0;
}