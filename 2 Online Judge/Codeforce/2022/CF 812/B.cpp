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

int a[100005];
int pre[100005];
int suf[100005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = suf[n] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = max(a[i], pre[i-1]);
    }

    for (int i = n; i >= 1 ; i--) {
        suf[i] = max(a[i], suf[i+1]);
    }

    for (int i = 2; i< n; i++) {
        if (a[i] < pre[i-1] && a[i] < suf[i+1]) {
            cout <<"no" << endl;
            return;
        }
    }
    cout <<"yes" << endl;
    return;
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
    while (t--) {
        solve();
    }
    return 0;
}