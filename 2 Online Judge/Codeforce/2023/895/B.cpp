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

pair<long long,long long>d[105];
long long n;
long long ok(long long mid) {
    for (int i = 1; i <= n; i++) {
        if (mid < d[i].fi) continue;
        long long dis = mid - d[i].fi ;
        if (dis *2 >= d[i].se ) {
            return 0;
        }    
    }
    return 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].fi >> d[i].se;
    }

    long long l = 1, r = 1e9;
    while (l < r) {
        long long mid = (l + r + 1) /2;
        if (ok(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
        // cout << l << ' ' << r <<endl;
    }
    cout << l << endl;
    // cout << ok(3);
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