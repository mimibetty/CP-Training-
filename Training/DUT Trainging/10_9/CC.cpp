
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

long long a[1000];
void solve() {
    int n;
    cin >> n;
    a[1] = 1;

    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
        a[i] %= n;
    }
    int limm =50;
    for (int i = 0; i <= 50; i++) {
        cout << a[i] << ' ' ; 
    }
    EL;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout  << x << endl;
    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}