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

int a[33];
bitset<4>bs;
void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // bs = a[i];
        // cout << bs << ' ';
    }   
    int cnt = n;
    for (int i = 1; i <= m; i++) {
        int o, k;
        cin >> o >> k;
        if (o == 1) {
            cnt++;
            a[cnt] = k;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        bs = a[i];
        cout << bs << ' ';
    }
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