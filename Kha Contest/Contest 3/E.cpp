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
long long a[33];
long long b[33];
void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        // cout << a[i];
    }
    for (int i = n; i >= 2; i--) {
        b[i-1] += b[i]/2;
    }
    if (b[1] == 0) {
        cout << "impossible";
        return;
    }
    double cd = 0.594604;
    // cout <<cd << endl;
    cout << 100 <<endl;
    cout << 100
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}