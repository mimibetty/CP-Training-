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

ll xx[200005];
void solve() {
    int n;
    cin >> n;
    long long x = 0;
    for (int i = 1; i < n; i++) {
        x+=i;
    }
    map<ll,int>d;
    for (int i = 1; i <= x; i++) {
        ll a;
        cin >> a;
        d[a]++;
        xx[n] = max(a, xx[n]);
    }
    int vt = 1;
    for (auto i : d) {
      while (d[i.fi] > 0) {
        d[i.fi] -= (n-vt);
        xx[vt] = i.fi;
        vt++;
      }  
    }

    for (int i = 1; i <= n; i++) cout << xx[i] << " ";
    EL;
    for (int i = 1; i <= n; i++) {
        xx[i] = 0;
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
    cin >> t;
    while (t--)   
    solve();
    
    return 0;
}