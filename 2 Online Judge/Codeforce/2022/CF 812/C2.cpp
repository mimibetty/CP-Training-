#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<long long, long long> pll;
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

int n;
vector<int>f[100005];
vector<int>p;
int cnt[100005];
void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (auto j : p) {
            if(j - i >= 0 && j - i < n) {
                f[i].pb(j);
                cnt[j - i] = 1;
            }        
        }
    }
    for (int i = 0; i < n; i++) {
        cout <<"STT  "<<  i << endl;
        for (auto j : f[i]) cout << j - i << "|" << cnt[j-i]<< ' ';
        cout << endl;
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
    
    for (int i = 0 ; i <= 2e5; i++) {
        if (sqrt(i) * sqrt(i) == i) p.pb(i);
    }


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}